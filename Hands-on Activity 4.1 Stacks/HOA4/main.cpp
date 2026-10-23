#include <iostream>
#include <string>
#include <stack> // for the STL version
#include "stack.h" // StackArray + StackList (custom implementations)

bool isMatchingPair(char open, char close) {
if (open == '(' && close == ')') return true;
if (open == '{' && close == '}') return true;
if (open == '[' && close == ']') return true;
return false;
}

/* ---------- Array-based version ---------- */
bool checkBalancedArray(const std::string& expr) {
StackArray<char> s;
for (char ch : expr) {
if (ch == '(' || ch == '{' || ch == '[') {
s.push(ch);
} else if (ch == ')' || ch == '}' || ch == ']') {
if (s.isEmpty()) {
std::cout << " Error: closing symbol '" << ch
<< "' found with no matching opening symbol.\n";
return false;
}
char top = s.pop();
if (!isMatchingPair(top, ch)) {
std::cout << " Error: mismatched symbols '" << top
<< "' and '" << ch << "'.\n";
return false;
}
}
}
if (!s.isEmpty()) {
std::cout << " Error: unclosed opening symbol(s) remain in the stack.\n";
return false;
}
return true;
}

/* ---------- Linked-list-based version ---------- */
bool checkBalancedList(const std::string& expr) {
StackList<char> s;
for (char ch : expr) {
if (ch == '(' || ch == '{' || ch == '[') {
s.push(ch);
} else if (ch == ')' || ch == '}' || ch == ']') {
if (s.isEmpty()) {
std::cout << " Error: closing symbol '" << ch
<< "' found with no matching opening symbol.\n";
return false;
}
char top = s.pop();
if (!isMatchingPair(top, ch)) {
std::cout << " Error: mismatched symbols '" << top
<< "' and '" << ch << "'.\n";
return false;
}
}
}
if (!s.isEmpty()) {
std::cout << " Error: unclosed opening symbol(s) remain in the stack.\n";
return false;
}
return true;
}

/* ---------- C++ STL std::stack version ---------- */
bool checkBalancedSTL(const std::string& expr) {
std::stack<char> s;
for (char ch : expr) {
if (ch == '(' || ch == '{' || ch == '[') {
s.push(ch);
} else if (ch == ')' || ch == '}' || ch == ']') {
if (s.empty()) {
std::cout << " Error: closing symbol '" << ch
<< "' found with no matching opening symbol.\n";
return false;
}
char top = s.top();
s.pop();
if (!isMatchingPair(top, ch)) {
std::cout << " Error: mismatched symbols '" << top
<< "' and '" << ch << "'.\n";
return false;
}
}
}
if (!s.empty()) {
std::cout << " Error: unclosed opening symbol(s) remain in the stack.\n";
return false;
}
return true;
}

int main() {
std::string testCases[] = {
"(A+B)+(C-D)",
"((A+B)+(C-D)",
"((A+B)+[C-D])",
"((A+B]+[C-D]}"
};

for (const std::string& expr : testCases) {
std::cout << "\n===============================\n";
std::cout << "Expression: " << expr << "\n";

std::cout << "\n[Array-based Stack]\n";
bool resA = checkBalancedArray(expr);
std::cout << "Result: " << (resA ? "VALID (balanced)" : "INVALID (not balanced)") << "\n";

std::cout << "\n[Linked-List-based Stack]\n";
bool resL = checkBalancedList(expr);
std::cout << "Result: " << (resL ? "VALID (balanced)" : "INVALID (not balanced)") << "\n";

std::cout << "\n[STL std::stack]\n";
bool resS = checkBalancedSTL(expr);
std::cout << "Result: " << (resS ? "VALID (balanced)" : "INVALID (not balanced)") << "\n";
}

return 0;
}
