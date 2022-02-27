# DESAFIO:

![imagem 42 labs](img/image.png)

> ⚠️ Status: Em desenvolvimento ⚠️

Nesse desafio tivemos que construir duas aplicações utilizando C: uma API e uma aplicação de interface de linha de comando(CLI).

## Ajustes e melhorias:

> API:

- [ ] Implementar uma requisição do tipo GET consumindo uma API externa;
- [ ] Devolver o resultado da requisição em uma URI;
- [ ] Devolver um código HTML na /home;

> CLI:

- [ ] Criar um código que imprima no terminal os logs;
- [ ] Agrupar e organizar os logs para facilitar a leitura;

## 💻 Pré-requisitos:

 Antes de começar, verifique se você atendeu aos seguintes requisitos:

* Você instalou a [libcurl](https://websetnet.net/pt/how-to-install-curl-on-ubuntu-quick-tip/)?
`Até este momento do projeto temos somente essa lib para instalar`

## 🚀 Baixando o labs_challenge:

```
git clone https://github.com/Dan-Sette/labs_challenge
```

## 🗝️ Como testar o funcionamento e utilizar o código:

Entre no diretório do projeto:
```
cd labs_challenge
```

Execute o comando `make`:
```
make
```

Rode o arquivo executável `labs_challenge` como abaixo:
```
./labs_challenge
```

Você verá que o terminal ficará em um loop:

![imagem do terminal](img/running.png)

Agora é só colar o link da porta ```http://localhost:8000 ``` no seu navegador, ou em um aplicativo como [Insomnia](https://insomnia.rest/download) ou [Postman](https://www.postman.com/downloads/)

![imagem do navegador](img/localhost.png)

##### Você pode testar com alguma URN diferente, como `/user` ou `/test`

> Se você estiver mandar uma requisição do tipo "POST" na URN `/test`, terá um resultado diferente em se tratando do método "GET";

Espero que tenha gostado. A parte bônus do projeto será implementada em um momento oportuno...🤓

[⬆ Voltar ao topo](#DESAFIO)<br>