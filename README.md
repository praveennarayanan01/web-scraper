# Web Scraper in C++

## What is a Web Scraper?
A web scraper is a tool used to extract data from websites automatically. It sends HTTP requests to a webpage, retrieves its content, and extracts useful information. This can be useful for tasks like monitoring prices, gathering statistics, or tracking weather updates.

## Purpose of This Web Scraper
The web scraper we are building will focus on extracting data along with the **date and time**. For instance, it can:
- Fetch news headlines with timestamps.
- Retrieve weather updates along with the date and time.
- Collect data logs for analysis.

## Main Parts of the Web Scraper
The scraper will consist of the following components:

### 1. HTTP Request Module
- **Purpose:** To send HTTP GET requests to the target website and retrieve the webpage content.
- **Tools:** Libraries like `libcurl` for C++.

### 2. HTML Parsing Module
- **Purpose:** To parse the webpage content (HTML) and locate the required data, such as text, links, or date and time fields.
- **Tools:** Libraries like `gumbo-parser` or custom string processing for basic tasks.

### 3. Data Extraction Logic
- **Purpose:** To identify and extract specific data points from the parsed HTML (e.g., date and time elements).
- **Tools:** Regex or custom filters to find relevant parts of the page.

### 4. Data Storage Module
- **Purpose:** To store the scraped data, including the date and time, in a structured format like a file (e.g., CSV) or a database.
- **Tools:** File handling using standard C++ libraries.

### 5. Logging and Error Handling
- **Purpose:** To log actions and errors to track scraper performance and handle issues like invalid URLs or connectivity errors.
- **Tools:** Standard C++ logging libraries or custom implementations.

### 6. Scheduler (Optional)
- **Purpose:** To automate the scraping process periodically.
- **Tools:** OS-level schedulers (e.g., `cron`) or custom time-based loops.

## Development Plan
1. Setup the development environment.
2. Build each component step-by-step.
3. Test and integrate the modules.
4. Add logging and error handling.
5. Optimize for performance and scalability.

## Requirements
- **Libraries:** `libcurl`, `gumbo-parser` (or alternatives).
- **Environment:** C++17 or higher for better standard library support.
- **Tools:** Compiler (e.g., GCC, Clang), Debugger.

## Expected Outcome
A functional web scraper in C++ that extracts data, including the date and time, from a target website and stores it for analysis.

## Note

Respect robots.txt and the website's policies.
Limit request rates to avoid overloading the server.
Use proper headers (e.g., User-Agent) to identify your scraper.
Avoid scraping sensitive or private data.

## Code

### fstream

[fstream](./markdown/fstream.md) is a C++ class for reading from and writing to files, combining the functionality of both `ifstream` (input file stream) and `ofstream` (output file stream). It allows you to open files, read their contents, write data to them, and manage file operations easily.

### customized exception 

A customized exception in C++ is a user-defined class derived from `std::exception` (or any other base class) that allows developers to throw and handle specific error conditions with tailored messages or additional data. It helps make error-handling more meaningful and specific to the application’s needs. But here in our program it handles more than just handling Exception so its called as [Customized Error](./markdown/error.md).