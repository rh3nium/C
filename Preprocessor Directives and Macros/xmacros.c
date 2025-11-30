#include <stdio.h>
#include <assert.h>

// this is just a useful macros that takes 'a'
// and makes it a string at compile preprocessor time
#define stringify(a) #a

// This is a way to do X-Macros
// essencially nested macros with predefininig data
// and can use C's preprocessor system to later
// define an X macros and change the bahvior of what
// gets text replaced. You will notice that in this 
// example I only use the 'token' but in the commented example
// I show a usecase with both 'token' and 'str'

// Look how easy it is to just add new tokens now its a single line
#define X_SYNTAX_TOKENS    \
    X(TOKEN_PLUS, "+")     \
    X(TOKEN_MINUS, "-")    \
    X(TOKEN_STAR, "*")     \
    X(TOKEN_DIVISION, "/") \
    // X(TOKEN_EQUAL, "=") \

#define X_KEYWORD_TOKENS      \
    X(TOKEN_IF, "if")       \
    X(TOKEN_ELSE, "else")   \
    X(TOKEN_FOR, "for")     \
    X(TOKEN_WHILE, "while") \

typedef enum TokenKind {
    TOKEN_ILLEGAL_TOKEN,
    TOKEN_EOF,
    
    // This literally just pastes 
    // TOKEN_PLUS,
    // TOKEN_MINUS,
    // TOKEN_STAR,
    // TOKEN_DIVISION,
    #define X(token, str) token,
        X_SYNTAX_TOKENS
    #undef X

    // This literally just pastes 
    // TOKEN_IF,
    // TOKEN_ELSE,
    // TOKEN_FOR,
    // TOKEN_WHILE,
    #define X(token, str) token,
        X_KEYWORD_TOKENS
    #undef X

    TOKEN_IDENTIFIER,

    TOKEN_COUNT
} TokenKind;

const char* token_kind_get_string(TokenKind kind) {
    assert(kind >= 0 && kind < TOKEN_COUNT);

    static char* token_strings[TOKEN_COUNT] = {
        stringify(TOKEN_ILLEGAL_TOKEN),
        stringify(TOKEN_EOF),

        // This literally just pastes 
        // "TOKEN_PLUS",
        // "TOKEN_MINUS",
        // "TOKEN_STAR",
        // "TOKEN_DIVISION",
        #define X(token, str) stringify(token),
            X_SYNTAX_TOKENS
        #undef X

        // This literally just pastes 
        // "TOKEN_IF",
        // "TOKEN_ELSE",
        // "TOKEN_FOR",
        // "TOKEN_WHILE",
        #define X(token, str) stringify(token),
            X_KEYWORD_TOKENS
        #undef X

        stringify(TOKEN_IDENTIFIER),
    };

    return token_strings[kind];
}

int main() {
    printf("token name: %s\n", token_kind_get_string(TOKEN_PLUS));
    printf("token name: %s\n", token_kind_get_string(TOKEN_IF));
    printf("token name: %s\n", token_kind_get_string(TOKEN_STAR));
    // printf("token name: %s\n", token_kind_get_string(TOKEN_EQUAL));
    printf("token name: %s\n", token_kind_get_string(-1)); // assert

    return 0;
}

/* Output:
token name: TOKEN_PLUS
token name: TOKEN_IF
token name: TOKEN_STAR
Assertion failed: (kind >= 0 && kind < TOKEN_COUNT), function token_kind_get_string, file xmacros.c, line 53.
*/

/*
typedef struct CKG_StringView {
    const char* data;
    u64 length;
} CKG_StringView;

// This is a real example taken from a lexer that I built
// that shows the utility of x macros, the idea is you change
// it in one place and it changes it everywhere else without 
// you having to do much or anything. Here I provide a string view
// which is just a string with a length. I then use my hashmap to
// map all strings to a coresponding token and then return that token.

IonTokenKind ionTokenGetSyntax(CKG_StringView sv) {
    static CKG_HashMap(CKG_StringView, IonTokenKind)* keyword_map = NULL;
    if (keyword_map == NULL) {
        ckg_hashmap_init_string_view_hash(keyword_map, CKG_StringView, IonTokenKind);
        #define X(token, str) ckg_hashmap_put(keyword_map, ckg_sv_create(str, sizeof(str) - 1), token);
            X_SYNTAX_TOKENS
        #undef X
    }

    if (!ckg_hashmap_has(keyword_map, sv)) {
        CKG_LOG_ERROR("WHAT: %.*s\n", sv.length, sv.data);
        return ION_TOKEN_ILLEGAL_TOKEN;
    }

    return ckg_hashmap_get(keyword_map, sv);
}
*/
