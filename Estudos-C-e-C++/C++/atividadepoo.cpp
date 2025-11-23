#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

[[noreturn]] void error(string s) {
    throw runtime_error(s);
}

[[noreturn]] void error(string s1, string s2) {
    error(s1 + s2);
}

struct Token {
    char kind;
    double value = 0;
};

class Token_stream {
public:
    Token get();
    void putback(Token);
    void ignore(char c);
private:
    bool full = false;
    Token buffer;
};

Token_stream ts;

void Token_stream::putback(Token t) {
    if (full)
        error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    if (!(cin >> ch)) return Token{quit};

    switch (ch) {
    case '(': case ')': 
    case print:
    case quit:
    case '+': case '-': case '*': case '/':
        return Token{ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4': 
    case '5': case '6': case '7': case '8': case '9': {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{number, val};
    }
    default:
        error("Bad token");
    }
}

void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (cin >> ch)
        if (ch == c) return;
}

double expression();

double primary() {
    Token t = ts.get();
    switch (t.kind) {
    case '(': {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case number:
        return t.value;
    default:
        error("primary expected");
    }
}

double term() {
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '*':
            left *= primary();
            break;
        case '/': {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double expression() {
    double left = term();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get();
            if (t.kind == quit) return;
            ts.putback(t);
            cout << result << expression() << endl;
        }
        catch (runtime_error& e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
    }
}

int main() {
    try {
        calculate();
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "exception \n";
        return 2;
    }
}