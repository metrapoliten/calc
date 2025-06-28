#include "view.hh"

#if 0
namespace {
  enum class Operation : std::uint8_t {
    PLUS,
    MINUS,
    MUL,
    DIV
  };

  enum class ActionBtn : char {
    PLUS  = '+',
    MINUS = '-',
    MUL   = '*',
    DIV   = '/',
    EQUAL = '=',
    AC    = 'A',
    DEL   = 'D'
  };

  struct Number {
    std::int64_t _val{0};
    int _len{0};
    bool _is_negative{false};
  };
  constexpr auto kMaxNumLen{10};
  std::optional<std::int64_t> toI64(std::string_view sv)
  {
    std::int64_t val{};
    if (std::from_chars(sv.data(), sv.data() + sv.size(), val)) {
      return val;
    }
    return std::nullopt;
  }
  void eq(Number x, Operation op, slint::ComponentHandle<AppWindow>& ui)
  {
    auto const aux = toI64(ui->get_val());
    if (aux) {
      if (op == Operation::PLUS) {
        std::print("(x = {}) + (aux = {}) = ", x._val, aux.value());
        x._val += aux.value();
        std::println("(x = {})", x._val);
        auto const temp = std::to_string(x._val);
        auto const s    = std::string_view(temp);
        ui->set_val(s);
        x._len = 0;
      }
    }
  }
}  // namespace
#endif

int main()
{
  View view{};
  view.run();
}
