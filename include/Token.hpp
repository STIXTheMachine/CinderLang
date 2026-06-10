//
// Created by jsoar on 6/9/2026.
//

#pragma once
#include <cstdint>
#include <optional>
#include <string_view>
using SymbolHandle = size_t;

// Good fucking god C++29 better fucking come with codegen
#define KEYWORD_LIST    \
    X(fn)               \
    X(return)           \
    X(void)             \
    X(swith)            \
    X(match)            \
    X(if)               \
    X(else)             \
    X(loop)             \
    X(break)            \


#define TYPENAME_LIST   \
    X(u8)               \
    X(u16)              \
    X(u32)              \
    X(u64)              \
    X(i8)               \
    X(i16)              \
    X(i32)              \
    X(i64)              \
    X(f16)              \
    X(f32)              \
    X(f64)              \
    X(bool)

#define PUNCTUATION_LIST    \
    X(R"(()", LParen)       \
    X(R"())", RParen)       \
    X(R"({)", LBrace)       \
    X(R"(})", RBrace)       \
    X(R"([)", LBracket)     \
    X(R"(])", RBracket)

#define FIXED_LEXEME_TYPE static inline constexpr std::string_view

#define DEF_KEYWORD_STRING(Keyword) FIXED_LEXEME_TYPE Keyword_##Keyword { #Keyword };
#define DEF_KEYWORD_ENUM(Keyword) Keyword_##Keyword,

#define DEF_TYPENAME_STRING(Typename) FIXED_LEXEME_TYPE Typename_##Typename { #Typename };
#define DEF_TYPENAME_ENUM(Typename) Typename_##Typename,

#define DEF_PUNCTUATION_STRING(PunctuationString, PunctuationName) FIXED_LEXEME_TYPE Punctuation_##PunctuationName { PunctuationString };
#define DEF_PUNCTUATION_ENUM(PunctuationString, PunctuationName)  Punctuation_##PunctuationName,

enum class TokenType
{
    #define X(Keyword) DEF_KEYWORD_ENUM(Keyword)
    KEYWORD_LIST
    #undef X

    #define X(Typename) DEF_TYPENAME_ENUM(Typename)
    TYPENAME_LIST
    #undef X

    #define X(PunctuationString, PunctuationName) DEF_PUNCTUATION_ENUM(PunctuationSeq, PunctuationName)
    PUNCTUATION_LIST
    #undef X
};

#define X(Keyword) DEF_KEYWORD_STRING(Keyword)
KEYWORD_LIST
#undef X

#define X(Typename) DEF_TYPENAME_STRING(Typename)
TYPENAME_LIST
#undef X

#define X(PunctuationString, PunctuationName) DEF_PUNCTUATION_STRING(PunctuationString, PunctuationName)
PUNCTUATION_LIST
#undef X

class Token
{
    size_t Line   = 0;
    size_t Column = 0;
    size_t Length = 0;
    std::optional<SymbolHandle> Symbol;
};