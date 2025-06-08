### App

```
west build -p always -b stm32f3_disco ./app
west flash
```

```
minicom -D /dev/ttyAMC0
```