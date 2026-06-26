#include "../include/lexer.h"

#include <fstream>


Token::Token(TokenType type, const std::string s){
    this->type = type;
    this->text = s;
}


static Line* processLine(const std::string& line, Arena* ar){
    Line* l = new (arena_alloc(ar, sizeof(Line))) Line();
    for (size_t i = 0; i < line.size(); ++i) {
    char ch = line[i];
    switch (ch) {
        case ' ': continue;
        case '#': return l;
        case '>':
            if (i + 1 < line.size() && line[i + 1] == '=') {
                *l << Token(TokenType::TOK_GE, ">=");
                ++i;
            } else *l << Token(TokenType::TOK_GT, ">");
            break;

        case '<':
            if (i + 1 < line.size() && line[i + 1] == '=') {
                *l << Token(TokenType::TOK_LE, "<=");
                ++i;
            } else *l << Token(TokenType::TOK_LT, "<");
            break;

        case '=':
            if (i + 1 < line.size() && line[i + 1] == '=') {
                *l << Token(TokenType::TOK_EQ, "==");
                ++i;
            }
            break;
        case '!':
            if (i + 1 < line.size() && line[i + 1] == '=') {
                *l << Token(TokenType::TOK_NE, "!=");
                ++i;
            }
            break;
        // OTHER MULTICHARACTER TOKENS
        
    }
}
    return l;
}


TokenStream* processFile(const std::string filename, Arena* ar){
    std::fstream f(filename, std::ios::in);
    TokenStream* ts = new (arena_alloc(ar, sizeof(TokenStream))) TokenStream();
    std::string line;
    while(getline(f, line)){
        *ts << *processLine(line, ar);
    }
    return ts;
}
