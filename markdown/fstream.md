# fstream

## ftsream open function inputs

### std::ios::in:

Open for reading input. Applicable for ifstream and fstream.

### std::ios::out:

Open for writing output. Applicable for ofstream and fstream.
If the file exists, its contents are truncated (erased). Use std::ios::app to append instead.

### std::ios::app (append):

Open for writing at the end of the file. Preserves the existing content and adds new data at the end.

### std::ios::ate (at end):

Open the file and move the file pointer to the end. Unlike std::ios::app, it allows reading and writing anywhere in the file.

### std::ios::trunc (truncate):

If the file exists, its content is erased when the file is opened. This is the default behavior for std::ios::out.

### std::ios::binary:

Open the file in binary mode. Without this flag, the file is opened in text mode, where line endings might be translated (e.g., \n to \r\n on Windows).