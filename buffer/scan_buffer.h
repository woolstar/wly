#ifndef SCAN_BUFFER_H
#define SCAN_BUFFER_H 1

#include <buffer.h>
#include <cstddef>
#include <cstdint>
#include <iterator>

namespace wly {

struct scan_buffer : public virtual buffer {
    struct iterator {
        using iterator_category = std::forward_iterator_tag ;
        using value_type = uint8_t ;
        using difference_type = std::ptrdiff_t ;
        using pointer = uint8_t * ;
        using reference = uint8_t & ;

        uint8_t * ptr_ ;

        iterator() noexcept : ptr_(nullptr) {}
        explicit iterator(uint8_t * p) noexcept : ptr_(p) {}

        reference operator*() const noexcept { return * ptr_ ; }
        pointer operator->() const noexcept { return ptr_ ; }

        iterator & operator++() noexcept { ++ ptr_ ; return *this ; }
        void operator++(int) noexcept { ++ ptr_ ; }

        bool operator==(iterator const & other) const noexcept { return ptr_ == other.ptr_ ; }
        bool operator!=(iterator const & other) const noexcept { return ptr_ != other.ptr_ ; }
    } ;

    struct const_iterator {
        using iterator_category = std::forward_iterator_tag ;
        using value_type = uint8_t ;
        using difference_type = std::ptrdiff_t ;
        using pointer = uint8_t const * ;
        using reference = uint8_t const & ;

        uint8_t const * ptr_ ;

        const_iterator() noexcept : ptr_(nullptr) {}
        explicit const_iterator(uint8_t const * p) noexcept : ptr_(p) {}
        const_iterator(iterator const & it) noexcept : ptr_(it.ptr_) {}

        reference operator*() const noexcept { return * ptr_ ; }
        pointer operator->() const noexcept { return ptr_ ; }

        const_iterator & operator++() noexcept { ++ ptr_ ; return *this ; }
        void operator++(int) noexcept { ++ ptr_ ; }

        bool operator==(const_iterator const & other) const noexcept { return ptr_ == other.ptr_ ; }
        bool operator!=(const_iterator const & other) const noexcept { return ptr_ != other.ptr_ ; }
    } ;

    iterator begin() noexcept { return iterator(begin_) ; }
    iterator end() noexcept { return iterator(curr_) ; }

    const_iterator begin() const noexcept { return const_iterator(begin_) ; }
    const_iterator end() const noexcept { return const_iterator(curr_) ; }

    scan_buffer() noexcept : buffer() {}

    scan_buffer(uint8_t * begin, uint8_t * end) noexcept
        : buffer(begin, end) {}

    scan_buffer(uint8_t * data, size_t size) noexcept
        : buffer(data, size) {}
} ;

} // namespace wly

#endif
