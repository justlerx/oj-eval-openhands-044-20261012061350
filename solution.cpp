#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class mystring
{
private:
    char *ch = nullptr;
    int len = 0;

public:
    // Friend function for operator<<
    friend ostream& operator<<(ostream& os, const mystring& str);

    mystring()
    {
        // TODO
        ch = nullptr;
        len = 0;
    }
    
    mystring(int _len, int c)
    {
        // TODO
        len = _len;
        ch = new char[len + 1];
        for (int i = 0; i < len; i++) {
            ch[i] = (char)c;
        }
        ch[len] = '\0';
    }
    
    mystring(string &c)
    {
        // TODO
        len = c.length();
        ch = new char[len + 1];
        strcpy(ch, c.c_str());
    }
    
    ~mystring()
    {
        // TODO
        if (ch != nullptr) {
            delete[] ch;
            ch = nullptr;
        }
        len = 0;
    }

    // Copy constructor for proper memory management
    mystring(const mystring& other) {
        len = other.len;
        if (other.ch != nullptr) {
            ch = new char[len + 1];
            strcpy(ch, other.ch);
        } else {
            ch = nullptr;
        }
    }

    // Assignment operator for proper memory management
    mystring& operator=(const mystring& other) {
        if (this != &other) {
            delete[] ch;
            len = other.len;
            if (other.ch != nullptr) {
                ch = new char[len + 1];
                strcpy(ch, other.ch);
            } else {
                ch = nullptr;
            }
        }
        return *this;
    }

    // Access operator
    char operator[](int x) {
        if (x >= 0 && x < len) {
            return ch[x];
        }
        return '\0';
    }

    // Less than operator
    bool operator<(const mystring& other) const {
        int min_len = (len < other.len) ? len : other.len;
        for (int i = 0; i < min_len; i++) {
            if (ch[i] < other.ch[i]) return true;
            if (ch[i] > other.ch[i]) return false;
        }
        return len < other.len;
    }

    // Equality operator
    bool operator==(const mystring& other) const {
        if (len != other.len) return false;
        for (int i = 0; i < len; i++) {
            if (ch[i] != other.ch[i]) return false;
        }
        return true;
    }

    // Addition operator
    mystring operator+(const mystring& other) const {
        mystring result;
        result.len = len + other.len;
        result.ch = new char[result.len + 1];
        
        if (ch != nullptr) {
            strcpy(result.ch, ch);
        }
        if (other.ch != nullptr) {
            strcat(result.ch, other.ch);
        }
        result.ch[result.len] = '\0';
        
        return result;
    }

    // Addition assignment operator
    mystring& operator+=(const mystring& other) {
        int new_len = len + other.len;
        char* new_ch = new char[new_len + 1];
        
        if (ch != nullptr) {
            strcpy(new_ch, ch);
        }
        if (other.ch != nullptr) {
            strcat(new_ch, other.ch);
        }
        new_ch[new_len] = '\0';
        
        delete[] ch;
        ch = new_ch;
        len = new_len;
        
        return *this;
    }

    // ADD function
    void ADD(const mystring& other) {
        *this += other;
    }

    // Output function
    void out() {
        if (ch != nullptr) {
            printf("%s", ch);
        }
    }

    // Get length function
    int get_len() {
        return len;
    }

    // Substring function
    mystring substr(int pos, int n) const {
        mystring result;
        if (pos < 0 || pos >= len || n <= 0) {
            return result;
        }
        
        int actual_len = (pos + n > len) ? (len - pos) : n;
        result.len = actual_len;
        result.ch = new char[result.len + 1];
        
        for (int i = 0; i < actual_len; i++) {
            result.ch[i] = ch[pos + i];
        }
        result.ch[result.len] = '\0';
        
        return result;
    }

    // Insert function
    void insert(int pos, const mystring& other) {
        if (pos < 0) pos = 0;
        if (pos > len) pos = len;
        
        int new_len = len + other.len;
        char* new_ch = new char[new_len + 1];
        
        // Copy first part
        for (int i = 0; i < pos; i++) {
            new_ch[i] = ch[i];
        }
        
        // Copy inserted string
        if (other.ch != nullptr) {
            for (int i = 0; i < other.len; i++) {
                new_ch[pos + i] = other.ch[i];
            }
        }
        
        // Copy remaining part
        for (int i = pos; i < len; i++) {
            new_ch[other.len + i] = ch[i];
        }
        
        new_ch[new_len] = '\0';
        
        delete[] ch;
        ch = new_ch;
        len = new_len;
    }

    // Erase function
    void erase(int pos, int n) {
        if (pos < 0 || pos >= len || n <= 0) {
            return;
        }
        
        int actual_n = (pos + n > len) ? (len - pos) : n;
        int new_len = len - actual_n;
        
        if (new_len == 0) {
            delete[] ch;
            ch = nullptr;
            len = 0;
            return;
        }
        
        char* new_ch = new char[new_len + 1];
        
        // Copy first part
        for (int i = 0; i < pos; i++) {
            new_ch[i] = ch[i];
        }
        
        // Copy remaining part
        for (int i = pos + actual_n; i < len; i++) {
            new_ch[i - actual_n] = ch[i];
        }
        
        new_ch[new_len] = '\0';
        
        delete[] ch;
        ch = new_ch;
        len = new_len;
    }
};

// Overload output operator
ostream& operator<<(ostream& os, const mystring& str) {
    if (str.ch != nullptr) {
        os << str.ch;
    }
    return os;
}

string str_in1, str_in2;
int n, id;
int main()
{
    cin >> id;
    if (id == 1)
    {
        mystring str1(100,'a');
        str1.out(); puts("");
        // cout << str1 << endl;
    }
    else if (id == 2)
    {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str2[x] << endl;
        }
    }
    else if (id == 3)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << endl;
    }
    else if (id == 4)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
    }
    else
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str3[x] << endl;
        }
        cout << str2.get_len() << " " << str3.get_len() << endl;
        cout << (int)(str2 < str3) << endl;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
        cout << str2.get_len() << endl;
    }
    return 0;
}