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
    constexpr buffer(uint8_t * begin, uint8_t * end, uint8_t * cur) noexcept
        : begin_(begin), end_(end), curr_(cur) {}

    template <typename T>
    constexpr buffer(T * begin, T * end) noexcept
        : begin_(ptr(begin)), end_(ptr(end)), curr_(begin_) {}

    constexpr buffer(buffer const & other) noexcept
        : begin_(other.begin_), end_(other.end_), curr_(other.curr_) {}
    constexpr buffer & operator=(buffer const & other) noexcept {
        begin_ = other.begin_;
        end_ = other.end_;
        curr_ = other.curr_;
        return *this;
    }

    constexpr buffer(uint8_t * adata, size_t asize) noexcept
        : begin_(adata), end_(adata + asize), curr_(adata) {}
    template <typename T>
    constexpr buffer(T * adata, size_t asize) noexcept
        : begin_(ptr<T>(adata)), end_(begin_ + asize), curr_(begin_) {}

    template <size_t N>
    constexpr buffer(uint8_t (& adata)[N]) noexcept
        : buffer( adata, N ) { }
    template <size_t N>
    constexpr buffer(char (& adata)[N]) noexcept
        : buffer( ptr( adata ), N ) { }

    template <typename T>
    static constexpr uint8_t *  ptr( T * aptr ) { return reinterpret_cast<uint8_t*>(aptr) ; }

    void  full() { curr_ = end_ ; }

    static buffer all( const buffer & src ) { return buffer( src.begin_, src.end_, src.end_ ) ; }
};

} // namespace wly

#endif
