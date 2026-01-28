# WSTAION

## 🇧🇷 Português (PT-BR)

### 📌 O que é o WSTAION?

**WSTAION** é uma ferramenta de linha de comando (CLI) escrita em **C**, criada para facilitar o fluxo de trabalho do dia a dia
Atualmente a ferramenta está na sua versão 0.1 e conta com a função de mapear programas do Linux e executá-los em sequência, garantindo que você não precise ficar abrindo diversos programas na sua máquina pessoal ou da sua empresa para realmente começar a trabalhar. Basta apenas mapear os programas desejados, e sempre que for iniciar o trabalho, apertar apenas um comando e esperar os programas abrirem pra você.

### Versões futuras
**** com um único comando.

A ideia é simples: você registra os caminhos de programas que usa no dia a dia (navegador, editor, IDE, etc.) e, quando quiser iniciar seu ambiente de trabalho, executa tudo automaticamente.

> ⚠️ **Versão atual:** `0.1`

Esta é uma versão inicial, focada exclusivamente em **Linux**.

---

### 🚀 Funcionalidades atuais (v0.1)

* Adicionar caminhos de programas ao WSTAION
* Armazenar os paths em um arquivo de configuração do usuário
* Executar todos os programas registrados em ordem
* Interface simples via terminal

Os caminhos são armazenados em:

```
~/.config/wstaion/path.txt
```

---

### 🧪 Exemplos de uso

Adicionar um programa:

```bash
wstaion add path "/usr/bin/firefox"
```

Remover um programa:

```bash
wstaion rm path "/usr/bin/firefox"
```

Iniciar o ambiente de trabalho:

```bash
wstaion workstart
```

---

### 📂 Estrutura de configuração

O WSTAION segue o padrão do Linux para configurações de usuário:

```
~/.config/wstaion/
└── path.txt
```

Cada linha do `path.txt` representa um programa que será executado na ordem em que foi adicionado.

---

### 🛣️ Roadmap (próximas features)

* 🔁 Verificação de paths duplicados antes de adicionar
* 🪟 Versão para Windows
* 🗑️ Comando para remover paths
* 📋 Listagem dos programas cadastrados
* ⚙️ Configurações extras via arquivo

---

### 🤝 Como contribuir

Contribuições são **muito bem-vindas** 🚀

Você pode contribuir de várias formas:

1. **Reportando bugs** (via Issues)
2. **Sugerindo novas features**
3. **Melhorando a documentação**
4. **Enviando código (Pull Requests)**

#### Passos básicos:

```bash
git fork

git clone <seu-fork>

crie uma branch para sua feature
git checkout -b minha-feature
```

Faça suas alterações, commit e envie um Pull Request explicando claramente o que foi feito.

---

### 🛠️ Build

Para compilar o projeto:

```bash
make
```

Ou manualmente:

```bash
gcc main.c -o wstaion
```

---

### ⚠️ Aviso

Este projeto ainda está em desenvolvimento inicial. Mudanças de comportamento e estrutura podem acontecer.

---

## 🇺🇸 English (EN)

### 📌 What is WSTAION?

**WSTAION** is a command-line tool (CLI) written in **C**, designed to **map Linux programs and execute them sequentially** using a single command.

The idea is simple: you register the paths of programs you use daily (browser, editor, IDE, etc.), and when you want to start your work environment, everything launches automatically.

> ⚠️ **Current version:** `0.1`

This is an early version, focused exclusively on **Linux**.

---

### 🚀 Current features (v0.1)

* Add program paths
* Store paths in a user config file
* Execute all registered programs in order
* Simple terminal-based interface

Paths are stored at:

```
~/.config/wstaion/path.txt
```

---

### 🧪 Usage examples

Add a program:

```bash
wstaion add path "/usr/bin/firefox"
```

Remove a program:

```bash
wstaion rm path "/usr/bin/firefox"
```

Start the workflow:

```bash
wstaion workstart
```

---

### 📂 Configuration structure

WSTAION follows the Linux user configuration standard:

```
~/.config/wstaion/
└── path.txt
```

Each line in `path.txt` represents a program that will be executed in the order it was added.

---

### 🛣️ Roadmap (upcoming features)

* 🔁 Duplicate path checking before adding
* 🪟 Windows version
* 🗑️ Command to remove paths
* 📋 List registered programs
* ⚙️ Extra configuration options

---

### 🤝 How to contribute

Contributions are **very welcome** 🚀

You can help by:

1. **Reporting bugs** (Issues)
2. **Suggesting features**
3. **Improving documentation**
4. **Submitting code (Pull Requests)**

#### Basic steps:

```bash
git fork

git clone <your-fork>

create a feature branch
git checkout -b my-feature
```

Make your changes, commit, and open a Pull Request explaining what you did.

---

### 🛠️ Build

To compile the project:

```bash
make
```

Or manually:

```bash
gcc main.c -o wstaion
```

---

### ⚠️ Disclaimer

This project is still in early development. Behavior and structure may change.
