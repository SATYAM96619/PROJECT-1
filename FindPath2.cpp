#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class URLShortener {
private:
    unordered_map<string, string> url_map; // stores short URL to long URL mapping
    unordered_map<string, string> reverse_map; // stores long URL to short URL mapping
    string base_url = "http://short.ly/"; // base URL for the short URLs
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // characters for base62 encoding
    int counter = 1; // incremental ID counter for short URL generation

    // Function to convert an ID to base62
    string toBase62(int id) {
        string short_url = "";
        while (id > 0) {
            short_url += chars[id % 62];
            id /= 62;
        }
        reverse(short_url.begin(), short_url.end()); // reverse to match correct order
        return short_url;
    }

public:
    // Function to shorten a URL
    string shortenURL(const string& long_url) {
        if (reverse_map.find(long_url) != reverse_map.end()) {
            return reverse_map[long_url]; // if already shortened, return the existing short URL
        }

        string short_code = toBase62(counter++);
        string short_url = base_url + short_code;
        
        // Store the mapping in both directions
        url_map[short_url] = long_url;
        reverse_map[long_url] = short_url;
        
        return short_url;
    }

    // Function to resolve a shortened URL to the original URL
    string resolveURL(const string& short_url) {
        if (url_map.find(short_url) != url_map.end()) {
            return url_map[short_url];
        }
        return ""; // Return empty if not found
    }
};

int main() {
    URLShortener urlShortener;

    // Test shortening and resolving URLs
    string long_url = "https://www.example.com";
    string short_url = urlShortener.shortenURL(long_url);
    cout << "Short URL for " << long_url << " is " << short_url << endl;

    string resolved_url = urlShortener.resolveURL(short_url);
    cout << "Resolved URL for " << short_url << " is " << resolved_url << endl;

    return 0;
}
