# MiniRT

### Run Valgrind

```bash
{
	make && valgrind --leak-check=full --show-leak-kinds=all ./miniRT > output.txt 2>&1 | wc -w
}
```
