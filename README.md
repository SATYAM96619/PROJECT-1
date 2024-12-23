# PROJECT-1
# URL Shortener - README

## Overview

This project implements a simple **URL Shortener** service that allows you to shorten long URLs and later resolve them back to their original form. The service uses **base62 encoding** to generate short URLs, ensuring that the URLs are compact and unique. It maintains mappings between short and long URLs, providing both **shortening** and **resolving** functionalities.

## Features

- **Shorten URLs**: Converts long URLs into a compact, shortened form that can be shared easily.
- **Resolve URLs**: Converts shortened URLs back to the original long URLs.
- **Base62 Encoding**: Uses a set of 62 characters (0-9, a-z, A-Z) to create unique short URLs.

## Technologies Used

- **C++**: The implementation is done using C++.
- **unordered_map**: Used for efficient lookups to map short URLs to long URLs and vice versa.
- **Base62 Encoding**: Short URLs are generated using an incremental ID counter that is converted to a base62 string.

## How It Works

1. **Shorten URL**:
   - Each long URL is converted into a unique short URL using an incremental ID counter.
   - The ID is converted into a **base62** string, which is appended to a base URL (e.g., `http://short.ly/`), forming the short URL.
   - The long URL and short URL are stored in two unordered maps:
     - **url_map**: Maps the short URL to the long URL.
     - **reverse_map**: Maps the long URL to the short URL.

2. **Resolve URL**:
   - Given a short URL, the system looks up the **url_map** to find the corresponding long URL.

## Functions

### `string shortenURL(const string& long_url)`

This function takes a **long URL** as input and returns the **shortened URL**.

- **Input**: A long URL (e.g., `https://www.example.com`).
- **Output**: A shortened URL (e.g., `http://short.ly/a1B2C3`).

If the long URL has already been shortened, it returns the existing short URL from the reverse mapping.

### `string resolveURL(const string& short_url)`

This function takes a **short URL** as input and returns the **original long URL**.

- **Input**: A short URL (e.g., `http://short.ly/a1B2C3`).
- **Output**: The original long URL (e.g., `https://www.example.com`).

If the short URL is not found, it returns an empty string.

### `string toBase62(int id)`

This helper function converts an **integer ID** to a **base62 encoded string**. This ensures that the generated short URL is short, unique, and human-readable.

- **Input**: An integer ID (e.g., `1`).
- **Output**: A base62 encoded string (e.g., `"a"`).

### `reverse_map` and `url_map`

- **reverse_map** stores the mapping from long URLs to their respective short URLs.
- **url_map** stores the mapping from short URLs to their respective long URLs.

## Example Usage

```cpp
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
```

### Output:

```
Short URL for https://www.example.com is http://short.ly/a
Resolved URL for http://short.ly/a is https://www.example.com
```

## Requirements

- C++11 or later (for using modern C++ features like `unordered_map` and `string`).
- No external libraries required, only standard C++ libraries.

## How to Compile and Run

1. Save the code to a file, for example `URLShortener.cpp`.
2. Open your terminal or command prompt.
3. Compile the C++ code using a C++ compiler:
   ```sh
   g++ -o URLShortener URLShortener.cpp
   ```
4. Run the compiled program:
   ```sh
   ./URLShortener
   ```

## Conclusion

This **URL Shortener** is a simple but effective service for shortening long URLs and resolving them back to their original form. It uses **base62 encoding** to generate compact and unique short URLs, and provides both **shortening** and **resolving** functionalities in a very efficient manner.
