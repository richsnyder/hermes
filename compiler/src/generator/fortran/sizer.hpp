#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_SIZER_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_SIZER_HPP

#include <memory>
#include <regex>
#include <sstream>
#include <boost/variant.hpp>

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

class sizer
{
public:
  typedef std::shared_ptr<sizer> pointer;

  static const std::size_t block_size = 4;

  sizer() = delete;
  sizer(sizer&&) = default;
  sizer(const sizer&) = delete;
  sizer& operator=(sizer&&) = default;
  sizer& operator=(const sizer&) = delete;
  sizer(const std::string& a_name, std::size_t a_size);
  sizer(const std::string& a_name,
        const std::string& a_length,
        std::size_t a_element_size);
  sizer(const std::string& a_name,
        const std::string& a_length,
        pointer a_content);

  bool is_fixed() const;

  void link(pointer a_next);

  operator std::string() const;
protected:
  class fixed_visitor : public boost::static_visitor<bool>
  {
  public:
    bool operator()(std::size_t a_length, std::size_t a_content) const;
    bool operator()(const std::string& a_length, std::size_t a_content) const;
    bool operator()(std::size_t a_length, pointer a_content) const;
    bool operator()(const std::string& a_length, pointer a_content) const;
  };

  class conversion_visitor : public boost::static_visitor<void>
  {
  public:
    conversion_visitor(std::ostream& a_out,
                       const std::string& a_name,
                       std::size_t a_header);

    void operator()(std::size_t a_length, std::size_t a_content) const;
    void operator()(const std::string& a_length, std::size_t a_content) const;
    void operator()(std::size_t a_length, pointer a_content) const;
    void operator()(const std::string& a_length, pointer a_content) const;

    std::string format(const std::string& a_template,
                       const std::string& a_name) const;
    std::ostream& m_out;
    std::string m_name;
    std::size_t m_header;
  };
private:
  std::string m_name;
  std::size_t m_header;
  boost::variant<std::size_t, std::string> m_length;
  boost::variant<std::size_t, pointer> m_content;
  pointer m_next;
};

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_SIZER_HPP
