#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace consts
{
    namespace abils
    {
        inline constexpr int base{8};
        inline constexpr int count{6};
        inline constexpr int racial{2};
        inline constexpr int form10{10};
        inline constexpr int form2{2};
    }    // namespace abils
    namespace hp
    {
        inline constexpr int min{1};
        inline constexpr int vlow{4};
        inline constexpr int low{6};
        inline constexpr int mid{8};
        inline constexpr int high{10};
        inline constexpr int vhigh{12};
    }    // namespace hp
    namespace level
    {
        inline constexpr int base{1};
    }
    namespace saves
    {
        inline constexpr int base{0};
        inline constexpr int count{3};
        inline constexpr int form3{3};
        inline constexpr int form4{4};
        inline constexpr int form2{2};
    }    // namespace saves
    namespace size
    {
        inline constexpr int mod0{0};
        inline constexpr int mod1{1};
        inline constexpr int mod2{2};
        inline constexpr int mod4{4};
        inline constexpr int mod8{8};
    }    // namespace size
}    // namespace consts

#endif
