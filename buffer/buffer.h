#ifndef BUFFER_H
#define BUFFER_H 1

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace wly {

struct buffer {
    using uint8_t = std::uint8_t ;

    uint8_t * begin_, * end_, * curr_ ;

    constexpr buffer() noexcept
        : begin_(nullptr), end_(nullptr), curr_(nullptr) {}

    constexpr buffer(uint8_t * begin, uint8_t * end) noexcept
        : begin_(begin), end_(end), curr_(begin) {}

    constexpr buffer(buffer const & other) noexcept
        : begin_(other.begin_), end_(other.end_), curr_(other.curr_) {}

    constexpr buffer & operator=(buffer const & other) noexcept {
        begin_ = other.begin_;
        end_ = other.end_;
        curr_ = other.curr_;
        return *this;
    }

    constexpr buffer(uint8_t * data, size_t size) noexcept
        : begin_(data), end_(data + size), curr_(data) {}

    buffer(char* data) noexcept
        : buffer((uint8_t *) data, strlen(data)) {}

    template <size_t N>
    buffer(char (&data)[N]) noexcept
        : buffer( (uint8_t *) data, N-1 ) { }
};

} // namespace wly

#endif
