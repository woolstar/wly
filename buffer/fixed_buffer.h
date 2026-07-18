#ifndef FIXED_BUFFER_H
#define FIXED_BUFFER_H

#include <buffer.h>

namespace wly {

template <int N = 1024>
class fixed_buffer : public buffer {
    static_assert(N > 0, "fixed_buffer size must be positive");

  public:
    fixed_buffer() noexcept
        : buffer(data_, N), data_{} {}

    fixed_buffer(fixed_buffer const & other) = delete ;
    fixed_buffer & operator=(fixed_buffer const & other) noexcept = delete ;

  protected:
    uint8_t data_[N];
};

} // namespace wly

#endif
