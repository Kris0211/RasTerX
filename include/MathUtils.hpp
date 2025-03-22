namespace rtx
{
    class MathUtils 
    {
    public:
        template <typename T>
        static T Max3(T a, T b, T c) { return std::max(std::max(a, b), c); }

        template <typename T>
        static T Min3(T a, T b, T c) { return std::min(std::min(a, b), c); }
    };
}
