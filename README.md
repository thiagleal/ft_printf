# ft_printf - Reimplementação da Função printf

ft_printf é um projeto desenvolvido como parte da jornada na 42 Lisboa. O objetivo é recriar a função `printf` da biblioteca padrão do C, implementando funcionalidades essenciais para formatação e exibição de strings, números e outros tipos de dados. Este projeto promove o aprendizado de conceitos avançados de programação em C, como manipulação de variáveis variádicas.

## 📚 Sobre o Projeto

ft_printf é uma implementação personalizada da função `printf`, que suporta uma variedade de especificadores de formato e oferece flexibilidade para manipulação de saída. O projeto é dividido em três partes principais:

1. **Especificadores de Formato**: Implementação de especificadores como `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, e `%%`.
2. **Manipulação de Variáveis Variádicas**: Uso de `va_list` para lidar com um número variável de argumentos.
3. **Tratamento de Erros e Precisão**: Garantia de compatibilidade com a função original, incluindo suporte para flags, largura e precisão.

## 🏆 Nota do Projeto

![Nota do Projeto](https://github.com/user-attachments/assets/14a444f4-6454-49ae-9713-fd571eb3c417)

## 🚀 Funcionalidades

### 🔤 Especificadores de Formato
- `%c`: Exibe um único caractere.
- `%s`: Exibe uma string.
- `%p`: Exibe um ponteiro em formato hexadecimal.
- `%d`/`%i`: Exibe um número inteiro com sinal.
- `%u`: Exibe um número inteiro sem sinal.
- `%x`/`%X`: Exibe um número em formato hexadecimal (minúsculo/maiúsculo).
- `%%`: Exibe o caractere `%`.

### 🧠 Manipulação de Variáveis Variádicas
- Uso de `va_list`, `va_start`, `va_arg` e `va_end` para acessar argumentos variádicos.

### Tratamento de Erros
- Retorna o número total de caracteres exibidos.
- Em caso de erro, retorna um valor negativo.

## 🖥️ Ambiente de Testes

O código foi testado em ambiente Linux, utilizando processadores baseados na arquitetura Intel. Caso utilize outro ambiente ou arquitetura, recomenda-se realizar testes adicionais para garantir a compatibilidade.

## ✅ Testes

O projeto inclui comandos no `Makefile` para facilitar a execução de testes. Siga os passos abaixo para testar a implementação:

1. **Clonar o repositório**

- Clone o repositório para sua máquina local: git clone https://github.com/thiagleal/ft_printf

2. **Adicionar a main de teste**  

- Certifique-se de incluir um arquivo chamado `main_ft_printf.c` dentro da pasta `src`. Esse arquivo deve conter os testes necessários para validar as funcionalidades do `ft_printf` e deve incluir `#include "ft_printf.h"`.

3. **Criar o binário de teste** 

- Use o comando abaixo para compilar o projeto e criar o binário de teste: `make test`.

4. **Executar o teste** 

- Após a criação do binário, execute o teste com: `./test_ft_printf`

5. **Remover os arquivos de teste** 

- Para limpar os arquivos gerados pelos testes, use: `make fcleantest`

## 📝 Contribuição

Sinta-se à vontade para contribuir com melhorias ou novas funcionalidades para o projeto. Abra uma issue ou envie um pull request!