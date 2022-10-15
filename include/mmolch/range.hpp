#ifndef MMOLCH_RANGE_HPP
#define MMOLCH_RANGE_HPP

namespace mmolch
{

template <typename T = int>
class range
{
public:
    /**
     * A Python-style range class for usage in range-based for loops.
     *
     * Usage:
     *   for (auto i : range<int>(0, 10, 3)) {
     *       std::cout << i << " ";
     *   }
     *  // output: 0 3 6 9
     * 
     * If the step size is 0 or it doesn't generate a sequence,
     * the start value will be set to the end value, effectively
     * treating it as already finished.
     * 
     * Arguments:
     *   start The start of the sequence
     *   end   The end of the sequence
     *   step  The step size of the sequence
     */
    explicit range(T start, T end, T step = 1) :
        m_start(start),
        m_end(end),
        m_step(step)
    {
        if ((m_step == 0) || ((m_step > 0) && (m_start > m_end)) || ((m_step < 0) && (m_start < m_end))) {
            // Treat invalid ranges as already finished
            m_start = m_end;
        }
    }

    struct iterator
    {
        T operator*() const { return m_value; }
        bool operator==(const iterator& other) const {
            if (m_range->m_step > 0)
                return m_value >= other.m_value;
            else
                return m_value <= other.m_value;
        }

        bool operator!=(const iterator& other) const { return !(*this == other); }

        iterator& operator++()
        {
            m_value += m_range->m_step;
            return *this;
        }

    private:
        const range* m_range;
        T m_value;

        explicit iterator(const range* range, T value) :
            m_range(range),
            m_value(value)
        {}

        friend class range;
    };

    iterator begin() { return iterator(this, m_start); }
    iterator end()   { return iterator(this, m_end); }

private:
    T m_start;
    T m_end;
    T m_step;
};

} // namespace mmolch

#endif // MMOLCH_RANGE_HPP
