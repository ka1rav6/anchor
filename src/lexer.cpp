#include "../include/lexer.h"

#include <fstream>


Token::Token(TokenType type, const std::string s){
    this->type = type;
    this->text = s;
}


static Line* processLine(const std::string& line, Arena* ar, size_t line_num){
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
        case '$':
            std::string ident = "";
            while (i < line.size() && line.at(++i) != ' '){
                char ch = line.at(i);
                if   (isalnum(ch)) ident += ch;
                else {
                    std::string error_msg = "The identifier can only contain characters from \"A-Z, a-z, 0-9, _\"\n";
                    error_msg += "The line " + std::to_string(line_num) + " contains an invalid identifier\n";
                    throw new std::runtime_error(error_msg);
                }
            }
            *l << Token(TokenType::TOK_IDENT, ident);
    }
}
    return l;
}


TokenStream* processFile(const std::string filename, Arena* ar){
    std::fstream f(filename, std::ios::in);
    TokenStream* ts = new (arena_alloc(ar, sizeof(TokenStream))) TokenStream();
    std::string line;
    size_t line_num = 0;
    while(getline(f, line)){
        line_num ++;
        *ts << *processLine(line, ar, line_num);
    }
    return ts;
}
