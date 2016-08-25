#include "generator/fortran/sizer.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

sizer::sizer(const std::string& a_name, std::size_t a_size)
  : m_name(a_name)
  , m_header(0)
  , m_length(1)
  , m_content(a_size)
  , m_next(nullptr)
{
  // empty
}

sizer::sizer(const std::string& a_name,
             const std::string& a_length,
             std::size_t a_element_size)
  : m_name(a_name)
  , m_header(block_size)
  , m_length(a_length)
  , m_content(a_element_size)
  , m_next(nullptr)
{
  // empty
}

sizer::sizer(const std::string& a_name,
             const std::string& a_length,
             pointer a_content)
  : m_name(a_name)
  , m_header(block_size)
  , m_length(a_length)
  , m_content(a_content)
  , m_next(nullptr)
{
  // empty
}

bool
sizer::is_fixed() const
{
  return boost::apply_visitor(fixed_visitor(), m_length, m_content);
}

void
sizer::link(pointer a_next)
{
  if (!m_next)
  {
    m_next = std::move(a_next);
  }
  else
  {
    m_next->link(a_next);
  }
}

sizer::operator std::string() const
{
  std::ostringstream out;
  conversion_visitor visitor(out, m_name, m_header);
  boost::apply_visitor(visitor, m_length, m_content);
  if (m_next)
  {
    out << " + " << static_cast<std::string>(*m_next);
  }
  return out.str();
}

bool
sizer::fixed_visitor::operator()(std::size_t a_length,
                                 std::size_t a_content) const
{
  return true;
}

bool
sizer::fixed_visitor::operator()(const std::string& a_length,
                                 std::size_t a_content) const
{
  return false;
}

bool
sizer::fixed_visitor::operator()(std::size_t a_length,
                                 pointer a_content) const
{
  fixed_visitor visitor;
  using boost::apply_visitor;
  return apply_visitor(visitor, a_content->m_length, a_content->m_content);
}

bool
sizer::fixed_visitor::operator()(const std::string& a_length,
                                 pointer a_content) const
{
  return false;
}

sizer::conversion_visitor::conversion_visitor(std::ostream& a_out,
                                              const std::string& a_name,
                                              std::size_t a_header)
  : m_out(a_out)
  , m_name(a_name)
  , m_header(a_header)
{
  // empty
}

void
sizer::conversion_visitor::operator()(std::size_t a_length,
                                      std::size_t a_content) const
{
  std::size_t size = m_header + a_length * a_content;
  size = ((size + block_size - 1) / block_size) * block_size;
  m_out << size;
}

void
sizer::conversion_visitor::operator()(const std::string& a_length,
                                      std::size_t a_content) const
{
  m_out << m_header << " + ";
  bool needs_padding = a_content % block_size != 0;
  if (needs_padding)
  {
    m_out << "((";
  }
  if (a_content != 1)
  {
    m_out << a_content << " * ";
  }
  m_out << format(a_length, m_name);
  if (needs_padding)
  {
    std::size_t n = block_size;
    std::size_t m = block_size - 1;
    m_out << " + " << m << ") / " << n << ") * " << n;
  }
}

void
sizer::conversion_visitor::operator()(std::size_t a_length,
                                      pointer a_content) const
{
}

void
sizer::conversion_visitor::operator()(const std::string& a_length,
                                      pointer a_content) const
{
  std::string var = "x_" + m_name;
  std::string sum = "s_" + m_name;
  conversion_visitor visitor(m_out, var, a_content->m_header);
  if (a_content->is_fixed())
  {
    m_out << m_header << " + (";
    pointer next = a_content->m_next;
    boost::apply_visitor(visitor, a_content->m_length, a_content->m_content);
    if (next)
    {
      m_out << " + ";
      conversion_visitor vis(m_out, var, next->m_header);
      boost::apply_visitor(vis, next->m_length, next->m_content);
    }
    m_out << ") * " << format(a_length, m_name);
  }
  else
  {
    // TBD
    m_out << "1024";
  }
}

std::string
sizer::conversion_visitor::format(const std::string& a_template,
                                  const std::string& a_name) const
{
  std::regex get_regex("get");
  std::regex braces_regex("\\{([^\\}]*)\\}");
  std::regex brackets_regex("\\[([^\\]]*)\\]");
  std::smatch match;
  if (std::regex_search(a_template, match, brackets_regex))
  {
    if (std::regex_search(a_name, get_regex))
    {
      return std::regex_replace(a_name, get_regex, "size");
    }
    else
    {
      return std::regex_replace(match.str(1), braces_regex, a_name);
    }
  }
  else
  {
    return std::regex_replace(a_template, braces_regex, a_name);
  }
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
