#include "../catch.hpp"

class IntRange : public Catch::MatcherBase<long long> {
    long long m_begin, m_end;
public:
    IntRange( long long begin, long long end ) : m_begin( begin ), m_end( end ) {}

    // Performs the test for this matcher
    virtual bool match( long long const& i ) const override {
        return i >= m_begin && i <= m_end;
    }

    // Produces a string describing what this matcher does. It should
    // include any provided data (the begin/ end in this case) and
    // be written as if it were stating a fact (in the output it will be
    // preceded by the value under test).
    virtual std::string describe() const override {
        std::ostringstream ss;
        ss << "is between " << m_begin << " and " << m_end;
        return ss.str();
    }
};

// The builder function
inline IntRange IsBetween( long long begin, long long end ) {
    return IntRange( begin, end );
}