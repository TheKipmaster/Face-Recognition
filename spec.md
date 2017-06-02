
# Trabalho 2

## Sistema de controle de acesso

Crie um sistema de controle de acesso para ser utilizado na entrada dos Laboratórios de Informática (Linf).

O sistema deve modelar todas as categorias de pessoas que acessam os laboratórios, incluindo:

* alunos,
* professores,
* funcionários da limpeza,
* funcionários da segurança (vigias),
* pessoal de suporte técnico do CIC (funcionários, estagiários e professores ligados à administração do suporte),
* pessoas externas (ou de empresas terceirizadas) que acessam os laboratórios para dar manutenção na infra-estrutura (hardware, cabeamento, móveis, paredes, ar-condicionado, etc).

A primeira funcionalidade do sistema é o cadastramento, em que cada usuário é inserido no banco de dados (BD).

* Caso vocês dominem algum sistema gerenciador de bancos de dados que se integra a C++ (de preferência um sistema orientado a objeto), sintam-se a vontade para usa-los.
* Caso contrário, este BD pode ser simplesmente um vetor de objetos das pessoas que é armazenado no disco, de preferência usando o formato JSON. Neste caso será necessário implementar funções simples de
  * inserir/remover instâncias no BD,
  * salvar/ler arquivos do BD,
  * fazer buscas no BD.

Para cada pessoa, o sistema armazena ao menos estas informações:

* Número do usuário, podendo ser o número de matrícula para membros da universidade ou o CPF para os usuários externos ou os terceirizados;
* Nome e nomes do meio;
* Sobrenome(s), incluindo sobrenomes compostos e partículas de sobrenomes ("de", "da", "e", etc.);
* Um vetor com identificadores de disciplinas e turmas em que está matriculado (ou em que dá aula) ou identificadores de outros tipos de reservas.
* Alguma forma que indique onde estão os arquivos que contém fotos do rosto dessa pessoa. Isso pode ser um vetor de strings com os paths dos nomes dos arquivos, ou seu sistema pode, por exemplo, criar um diretório para cada número de matrícula e armazenar todas as fotos de cada usuário nesse diretório.

Ao serem cadastrados, os usuários digitam as informações necessárias e o sistema também adquire fotos do rosto do usuário. Essas fotos devem conter somente a região do rosto das pessoas, e preferencialmente serão armazenadas ao menos 10 fotos por pessoa, com variações de expressão facial, oclusões parciais e leves mudanças na pose da cabeça.

O sistema também precisa cadastrar reservas, que podem ser para aulas de disciplinas e também podem ser horários para limpeza, manutenção ou mesmo reservas individuais, por exemplo, para alguma reunião esporádica ou uma sessão preparatória para maratona de programação. Cada reserva possui ao menos essas informações:

* Autor da reserva, identificado por um número (ex. matricula);
* Propósito da reserva (um string com o título, ex. nome da disciplina);
* Se for para aula, informe o código da disciplina e da turma;
* Número da(s) sala(s) onde o evento ocorrerá;
* Horários;
* Informe se é uma reserva recorrente (ou seja, toda semana, toda terça e quinta). Se for recorrente, informe a primeira e a última data da reserva.
* Será necessário armazenar um vetor indicando o número de matrícula de todos que participarão do evento (por exemplo, todos alunos, professores e monitores de uma disciplina, ou todos os funcionários da limpeza que estarão lá naquele horário). Isso pode ser como um atributo da classe de reserva ou pode ser armazenado em outra classe ou estrutura de dados.

Obviamente, além das funcionalidades de cadastro de usuários e de reservas, o sistema também deverá ter a funcionalidade de busca (query & retrieval), ou seja, quando um usuário chega no laboratório, ele deve informar seu número de matrícula e o sistema deve capturar uma foto (ou uma sequência de fotos) do seu rosto, que serão comparadas com as da base de dados. As seguintes ações podem ocorrer:

* Ao confirmar se o usuário está cadastrado, o sistema informa se ele tem permissão de entrar no Linf e também informa para qual sala ele deve ir.
* O número do usuário pode estar cadastrado, porém sua foto é muito diferente daquelas armazenadas no sistema. Com isso, o sistema avisa o operador e o guarda deveria pedir sua carteirinha para confirmar a identidade. Caso confirmada, o sistema captura mais fotos deste usuário para tornar o cadastro de fotos mais robusto.
* O usuário não está cadastrado. Neste caso o segurança decide se cadastra-o como novo usuário (por exemplo, se a pessoa está lá para uma manutenção esporádica), ou se o impede de entrar no laboratório.
Na caixa de texto abaixo, por favor indique o link do repositório Git que contém seu projeto.

Seguindo os padrões anteriores, o projeto deverá conter programas e documentação. A documentação deve incluir diagramas de classe e ao menos um diagrama de sequência.

O uso de interfaces gráficas (GUI) é opcional.
