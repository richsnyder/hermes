#include "generator/utilities.hpp"

namespace hermes {
namespace compiler {
namespace generator {

std::vector<std::string>
split(const std::string& a_string)
{
  std::vector<std::string> parts;
  std::string::size_type pos = 0;
  std::string::size_type dot;
  while (!a_string.empty())
  {
    dot = a_string.find('.', pos);
    if (dot == std::string::npos)
    {
      parts.push_back(a_string.substr(pos, std::string::npos));
      break;
    }
    else
    {
      parts.push_back(a_string.substr(pos, dot - pos));
      pos = dot + 1;
    }
  }
  return parts;
}

std::string
stem(const std::string& a_path)
{
  std::string::size_type beg = a_path.rfind('/');
  std::string::size_type end = a_path.rfind('.');
  if (beg == std::string::npos)
  {
    return a_path.substr(0, end);
  }
  beg++;
  if (end == std::string::npos || end < beg)
  {
    return a_path.substr(beg);
  }
  return a_path.substr(beg, end - beg);
}

std::string
to_camel(const std::string& a_label)
{
  bool up = true;
  std::string label;
  for (auto c : a_label)
  {
    if (c == '_')
    {
      up = true;
    }
    else if (up)
    {
      up = false;
      label += std::toupper(c);
    }
    else
    {
      label += c;
    }
  }
  return label;
}

std::string to_hex(unsigned long a_value)
{
  int width = 2;
  std::ostringstream out;

  if (a_value > 1)
  {
    double x = std::ceil(std::log(a_value) / std::log(16));
    width = static_cast<int>(x + 0.001);
    width += width % 2;
  }

  out << "0x";
  out << std::hex << std::uppercase;
  out << std::setfill('0') << std::setw(width);
  out << a_value;

  return out.str();
}

} // generator namespace
} // compiler namespace
} // hermes namespace
