#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace consts
{
    namespace abils
    {
        inline constexpr unsigned short base{8};
        inline constexpr unsigned short count{6};
        inline constexpr unsigned short racial{2};
        inline constexpr unsigned short form10{10};
        inline constexpr unsigned short form2{2};
    }    // namespace abils
    namespace hp
    {
        inline constexpr unsigned short min{1};
        inline constexpr unsigned short vlow{4};
        inline constexpr unsigned short low{6};
        inline constexpr unsigned short mid{8};
        inline constexpr unsigned short high{10};
        inline constexpr unsigned short vhigh{12};
    }    // namespace hp
    namespace level
    {
        inline constexpr unsigned short base{1};
    }
    namespace saves
    {
        inline constexpr unsigned short base{0};
        inline constexpr unsigned short count{3};
        inline constexpr unsigned short form3{3};
        inline constexpr unsigned short form4{4};
        inline constexpr unsigned short form2{2};
    }    // namespace saves
    namespace size
    {
        inline constexpr unsigned short mod0{0};
        inline constexpr unsigned short mod1{1};
        inline constexpr unsigned short mod2{2};
        inline constexpr unsigned short mod4{4};
        inline constexpr unsigned short mod8{8};
    }    // namespace size
}    // namespace consts

#endif
