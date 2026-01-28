# WSTAION
> ⚠️ **Versão atual:** `0.1`

## 🇧🇷 Português (PT-BR)

### O que é o WSTAION?

**WSTAION** é uma ferramenta de linha de comando (CLI) escrita em **C**, criada para facilitar o fluxo de trabalho do dia a dia.
Atualmente a ferramenta está na sua versão 0.1 e conta com a função de mapear programas do Linux e executá-los em sequência, garantindo que você não precise ficar abrindo diversos programas na sua máquina pessoal ou da sua empresa para realmente começar a trabalhar. Basta apenas mapear os programas desejados, e sempre que for iniciar o trabalho, apertar apenas um comando e esperar os programas abrirem pra você.


### 🚀 Funcionalidades atuais (v0.1)

* Adicionar caminhos de programas que vão ser executados
* Remover caminhos adcionados no path
* Armazenar os paths em um arquivo de configuração do usuário
* Executar todos os programas mapeados sem sobrecarregar a memória


### Features futuras em desenvolvimento
* **Salvar palavras chaves em um dicionário pessoal**
    A idéia é focar em salvar diretamente no terminal conceitos e palavras(técnicas ou não) e escrever um breve resumo do seu significado, podendo ser útil para novos colaboradores       ou projetos que exigem aprender vários novos conceitos e palavras chave que precisam ser relembradas com frequência ou eventualmente, e com isso, tornara consulta mais rápida e       eficiente pela natureza do terminal estar de fácil acesso a todo momento.
  
* **Versão para Windows**
    (parcialmente feita)Adcionar uma versão para Windows, para ser utilizada via PowerShell.

* **Verificação de paths duplicados antes de adicionar**
* **Listagem dos programas cadastrados**
* **Configurações extras via arquivo**

---

Os caminhos são armazenados em:

```
~/.config/wstaion/path.txt
```
Cada linha do `path.txt` representa um programa que será executado na ordem em que foi adicionado.
---

### 🧪 Documentação de uso
###Linux
**Requisitos**
* Linux
* GCC
* MAKE
* GIT

Caso for uma distro baseada em Debian/Unbutu
```bash
sudo apt install build-essential git
```
Clone o repositório 
```bash
git clone https://github.com/SEU_USUARIO/wstaion.git
cd wstaion
```
Compile usando o comando
```bash
make
```
Ou compile manualmente
```bash
gcc main.c -o wstaion
```

Para poder executar o wstaion de qualquer lugar do terminal, mova o binário para /usr/local/bin
```bash
sudo mv wstaion /usr/local/bin/
```
Após isso, teste algum comando já funcional

**Adicionar um programa:**

Você pode mapear um programa digitando o seu caminho completo da raiz.
```bash
wstaion add path "/usr/bin/firefox"
```

**Remover um programa:**

Para remover um caminho adcionado basta usar o comando **rm**
```bash
wstaion rm path "/usr/bin/firefox"
```

**Iniciar o ambiente de trabalho:**

Agora, para iniciar os programas basta usar o seguinte comando.
```bash
wstaion workstart
```
---
###Windows
## Instalação no Windows
No Windows, um comando só pode ser executado de qualquer lugar se o executável estiver em uma pasta listada na variável de ambiente **PATH**.

Por isso, é necessário:
- colocar o `wstaion.exe` em uma pasta fixa
- adicionar essa pasta ao PATH do usuário

Esse processo **não altera o sistema**, apenas o usuário atual.

---

### Passo a passo

#### 1. Baixar o executável
- Acesse a aba **Releases** deste repositório
- Baixe o arquivo `.zip` da versão Windows
- Extraia o conteúdo

---

#### 2. Criar uma pasta para executáveis do usuário
Crie a seguinte pasta (caso ainda não exista):

```bash
C:\Users\SeuUsuario\bin
```
Essa pasta será usada para armazenar comandos personalizados.
---

#### 3. Mover o executável
Mova o arquivo **wstaion.exe** para dentro da pasta **C:\Users\SeuUsuario\bin**

Exemplo final:
```bash
C:\Users\Maicon\bin\wstaion.exe
```

---

#### 4. Adicionar a pasta ao PATH do usuário
1. Pressione **Win + R**

2. Digite: **sysdm.cpl**
3. Vá até a aba **Avançado**
4. Clique em **Variáveis de Ambiente**
5. Em **Variáveis do usuário**, selecione **Path**
6. Clique em **Editar**
7. Clique em **Novo**
8. Adicione: **C:\Users\SeuUsuario\bin**
9. Confirme tudo com **OK**

⚠️ Use apenas **Variáveis do usuário**.  
Não é necessário permissão de administrador.

---

#### 5. Reiniciar o terminal
Feche todos os terminais abertos e abra um novo.

---

#### 6. Testar a instalação
No terminal (CMD ou PowerShell), execute:

```cmd
where wstaion
```
Se o caminho do executável for exibido, a instalação foi concluída com sucesso.

Agora teste:
```cmd
wstaion help
```





Compilar com MinGW:
gcc main.c platform_windows.c -o wstaion.exe


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

### ⚠️ Aviso

Este projeto ainda está em desenvolvimento inicial. Mudanças de comportamento e estrutura podem acontecer.

