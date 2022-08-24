# SimpleBashUtils
This is an implementation of of Bash text utilities: cat, grep. The programs are developed in C language of C11 standard using gcc compiler.

### Build
```
cd src/cat
make build
cd ../grep
make build
```

### cat usage
`cat [OPTION] [FILE]...`

### cat options
| Options | Description |
| ------ | ------ |
| -b (GNU: --number-nonblank) | numbers only non-empty lines |
| -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  |
| -n (GNU: --number) | number all output lines |
| -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines |
| -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  |

### grep Usage
`grep [options] template [file_name]`

### grep Options
| Options | Description |
| ------ | ------ |
| -e | pattern |
| -i | Ignore uppercase vs. lowercase.  |
| -v | Invert match. |
| -c | Output count of matching lines only. |
| -l | Output matching files only.  |
| -n | Precede each matching line with a line number. |
| -h | Output matching lines without preceding them by file names. |
| -s | Suppress error messages about nonexistent or unreadable files. |
| -f file | Take regexes from a file. |
| -o | Output the matched parts of a matching line. |
