#include <bits/stdc++.h>
using namespace std;

class BloomFilter {
private:
  int width;
  vector<bool> bits;

  int hash1(const string &s) const {
    int val = 0;
    for (char c : s) {
      val = (val * 31 + c) % width;
    }
    return abs(val);
  }

  int hash2(const string &s) const {
    int val = 0;
    for (char c : s) {
      val = (val * 37 + c) % width;
    }
    return abs(val);
  }

  int hash3(const string &s) const {
    int val = 0;
    for (char c : s) {
      val = (val * 41 + c) % width;
    }
    return abs(val);
  }

  string toLower(const string &s) const {
    string res = s;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
  }

public:
  BloomFilter(int w) : width(w) { bits = vector<bool>(width, false); }

  void update(const string &item) {
    string word = toLower(item);
    int h1 = hash1(word);
    int h2 = hash2(word);
    int h3 = hash3(word);

    bits[h1] = true;
    bits[h2] = true;
    bits[h3] = true;
  }

  bool evaluate(const string &item) const {
    string word = toLower(item);
    int h1 = hash1(word);
    int h2 = hash2(word);
    int h3 = hash3(word);

    // cout << "Hash positions for '" << item << "':" << endl;
    // cout << "h1: " << h1 << " (bit: " << bits[h1] << ")" << endl;
    // cout << "h2: " << h2 << " (bit: " << bits[h2] << ")" << endl;
    // cout << "h3: " << h3 << " (bit: " << bits[h3] << ")" << endl;

    return bits[h1] && bits[h2] && bits[h3];
  }

  void printFilter() const {
    cout << "Bloom Filter bits:" << endl;
    for (int i = 0; i < width; i++) {
      cout << bits[i] << " ";
    }
    cout << endl;
  }
};

int test() {
  vector<string> input = {"Shubham", "test", "Shubham",
                          "hash",    "test", "Shubham"};
  int width = 97;

  BloomFilter bf(width);
  cout << "Inserting items into Bloom Filter..." << endl;
  for (const string &item : input) {
    bf.update(item);
  }

  bf.printFilter();

  cout << "Shubham: "
       << (bf.evaluate("Shubham") ? "May be present" : "not be present")
       << endl;
  cout << "example: "
       << (bf.evaluate("example") ? "May be present" : "not be present")
       << endl;
  cout << "test: "
       << (bf.evaluate("test") ? "May be present" : "not be present") << endl;
  cout << "hash: "
       << (bf.evaluate("hash") ? "May be present" : "not be present") << endl;

  return 0;
}
