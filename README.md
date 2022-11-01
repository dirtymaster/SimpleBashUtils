# SimpleBashUtils
1. [In English](#description)
2. [На русском](#описание)
### Description
Implementation of of Bash text utilities: cat, grep. The programs are developed in C language of C11 standard using gcc compiler.

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
***

### Описание
Реализация текстовых утилит Bash: cat, grep. Программы разработаны на языке C стандарта C11 с использованием компилятора gcc.

### Сборка
```
cd src/cat
make build
cd ../grep
make build
```

### Использование cat
`cat [OPTION] [FILE]...`

### Опции cat
| Опции | Описание |
| ------ | ------ |
| -b (GNU: --number-nonblank) | нумерует только непустые строки |
| -e предполагает и -v (GNU only: -E то же самое, но без применения -v) | также отображает символы конца строки как $  |
| -n (GNU: --number) | нумерует все выходные строки |
| -s (GNU: --squeeze-blank) | сжимает несколько смежных пустых строк |
| -t предполагает и -v (GNU: -T то же самое, но без применения -v) | также отображает табы как ^I |

### Использование grep
`grep [options] template [file_name]`

### Опции grep
| Опции | Описание |
| ------ | ------ |
| -e | Шаблон |
| -i | Игнорирует различия регистра.  |
| -v | Инвертирует смысл поиска соответствий. |
| -c | Выводит только количество совпадающих строк. |
| -l | Выводит только совпадающие файлы.  |
| -n | Предваряет каждую строку вывода номером строки из файла ввода. |
| -h | Выводит совпадающие строки, не предваряя их именами файлов. |
| -s | Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах. |
| -f file | Получает регулярные выражения из файла. |
| -o | Печатает только совпадающие (непустые) части совпавшей строки. |
