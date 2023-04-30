# DIM0120 - 2023.1 – Gerenciador de Playlists com Lista Encadeada (Projeto 1)

## Equipe:
A equipe é composta por dois alunos do curso de Bacharelado em Tecnologia da Informação, são eles:
- Glória Maria Souza Campêlo (20220034667)
* Marcos Vinícius Noberto de Oliveira (20220049973)


## Como compilar e rodar o programa:
__Para acessar o programa:__
1. Acesse a pasta 'build';
2. Execute o arquivo 'MeuProjeto.exe'

Pronto, você já tem acesso ao programa :)

__Quanto aos exemplos de entradas:__ <br>
O programa contém um menu principal que guia o usuário por outros menus e pelas funções da aplicação, portanto a navegação é bem simples.
O Menu principal possui 3 opções para submenus: "Gerenciar musicas", "Gerenciar playlists" e "Gerenciar musicas em playlists". Cada função leva o usuário para um segundo menu correspondente à ação que o mesmo deseja realizar.<br>
Alem disso, o menu principal também conta com uma opção para "Selecione uma playlist para tocar" e outra "O que esta tocando agora?" que informa o usuário qual música está tocando no momento.<br>
Finalmente, o menu exibe a função "Sair", que encerra o programa.<br>
Para selecionar uma ação basta digitar o número ao lado da opção desejada e apertar a tecla 'enter'.<br><br>

_Durante toda a execução do programa, são impressas instruções claras para o usuário de como interagir com a aplicação._

<br><br>
__Funções do programa__
<br><br>

"Gerenciar Musicas"
<br>
O Gerenciar Musicas é uma funcionalidade para utilizar o CRUD de todas as músicas existentes no projeto. Para acessa-lá, basta digitar "1" na tela inicial do programa. 
Após o acesso, o usuário receberá 3 opções de modificações, sendo elas: Adicionar, Remover e Listar Musicas. Ambas podem ser acessadas respectivamente digitando "1", "2" ou "3" no prompt de comando.
<br>
    1. Adicionar Musica
        O adicionar musica serve para cadastro da música no sistema, mas não necessáriamente em uma playlist. Para realizar o cadastro, basta digitar, no prompt de comando, o título da música(Ex: "Titulo"), pressionar a tecla enter, e logo em seguida digitar o nome do artista respónsavel pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se os dados preenchido são válidos e se o registro foi bem efetuado.
<br>
    2. Remover Musica
        O remover musica serve para excluir uma música no sistema, retirando-a de qualquer playlist em que estivesse. Para realizar a remoção, basta digitar, no prompt de comando, o título da música(Ex: "Titulo"), pressionar a tecla enter, e logo em seguida digitar o nome do artista respónsavel pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar  se o exclusão foi bem-sucedida e se a música foi removida de alguma playlist.
<br>
    3. Listar Musica
        O listar música imprime uma lista, enumerada em ordem crescente, com todas as músicas cadastradas no sistema.
<br>
Após o acesso do Gerenciar Musicas, o usuário pode acessar a função "Voltar" digitando "4" no prompt de comando, sendo retornado para o menu inicial do sistema.
<br><br>

"Gerenciar Playlists"
<br>
O Gerenciar Playlists é uma funcionalidade para utilizar o CRUD das playlists de musica. Para acessa-lá, basta digitar "2" na tela inicial do programa. 
Após o acesso, o usuário receberá 3 opções de modificações, sendo elas: Adicionar, Remover e Listar Playlists. Ambas podem ser acessadas respectivamente digitando "1", "2" ou "3" no prompt de comando.
<br>
    1. Adicionar Playlists
        O adicionar playlists serve para cadastro de novas playlists pro sistema. Para realizar o cadastro, basta digitar, no prompt de comando, o nome da playlist(Ex: "Minhas Musicas") seguido da tecla enter. Após isso, o sistema manda uma mensagem de confirmação para informar se os dados preenchido são válidos e se o registro foi bem efetuado.
<br>
    2. Remover Playlists
        O remover playlists serve para excluir uma playlist do sistema. Para realizar a remoção, basta digitar, no prompt de comando, o nome da playlist(Ex: "Minhas Musicas") seguido da tecla enter. Após isso, o sistema manda uma mensagem de confirmação para informar se o exclusão foi bem-sucedida.
<br>
    3. Listar Playlists
        O listar playlists imprime uma lista, enumerada em ordem crescente, com todas as playlists cadastradas no sistema.
<br>
Após o acesso do Gerenciar Playlists, o usuário pode acessar a função "Voltar" digitando "4" no prompt de comando, sendo retornado para o menu inicial do sistema.
<br><br>

"Gerenciar Musicas em Playlists"
<br>
O Gerenciar Playlists é uma funcionalidade para utilizar o CRUD das músicas que estão dentro de uma determinada playlist. Para acessa-lá, basta digitar "3" na tela inicial do programa. 
Após o acesso, o sistema imprime uma lista enumerada das playlists existentes no programa, permitindo que o usuário digite o número equivalente a playlist que ele quer modificar.
Depois de escolher a playlist desejada, o usuário receberá 4 opções de modificações, sendo elas: Adicionar, Remover, Listar e Mover as músicas dentro da playlists correspondente. Ambas podem ser acessadas respectivamente digitando "1", "2", "3" ou "4" no prompt de comando.
<br>
    1. Adicionar Musicas a Playlist
        O adicionar musicas a playlist serve para cadastro de novas musicas para a playlist, também sendo cadastrada na lista de músicas gerais caso ainda não existisse. Para realizar o cadastro, basta digitar, no prompt de comando, o título da música(Ex: "Titulo"), pressionar a tecla enter, e logo em seguida digitar o nome do artista respónsavel pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se os dados preenchido são válidos e se o registro foi bem efetuado.
<br>
    2. Remover Musicas da Playlist
        O remover musicas da playlist serve para excluir uma musica para a playlist, mas não necessáriamente do sistema. Para realizar a remoção, basta digitar, no prompt de comando, o título da música(Ex: "Titulo"), pressionar a tecla enter, e logo em seguida digitar o nome do artista respónsavel pela obra (Ex: "Artista"). Após isso, o sistema manda uma mensagem de confirmação para informar se o exclusão foi bem-sucedida.
<br>
    3. Listar Musicas da Playlist
        O listar musicas da playlist imprime uma lista, enumerada em ordem crescente, com todas as musicas existentes dentro da playlist selecionada anteriormente.
<br>
    4. Mover Musicas da Playlist
        O mover musicas da playlist imprime uma lista, enumerada em ordem crescente, com todas as musicas existentes dentro da playlist, após isso, basta digitar a posição da música que deseja ser movida(Ex: "4"), para a posição que deseja move-lá (Ex: "1"), arrastando a musica correspondente a po sição realocada e todas entre elas para uma posição a mais. Após isso, o sistema manda uma mensagem de confirmação para informar se a realocação da musica foi bem-sucedida.
<br>
Após o acesso do Gerenciar Musicas Playlists, o usuário pode acessar a função "Voltar" digitando "5" no prompt de comando, sendo retornado para o menu inicial do sistema.
<br><br>

"Selecione uma playlist para tocar"
<br>
É uma funcionalidade para selecionar a playlist que terá suas musicas percorridas pelos sistema. Para acessa-lá, basta digitar "4" na tela inicial do programa. 
Após o acesso, o sistema imprime uma lista enumerada das playlists existentes no programa, permitindo que o usuário digite no prompt o número equivalente a playlist que ele quer ouvir(Ex: "1"). Caso a entrada seja válida, o sistema manda uma mensagem de confirmação e retorna para o menu inicial.
<br><br>

"O que está tocando agora?"
<br>
É uma funcionalidade para tocar a próxima música da playlist que está sendo percorrida pelo sistema. Caso nenhuma playlist seja selecionada, ele percorrerá a primeira. Para acessa-lá, basta digitar "5" na tela inicial do programa. 
Após o acesso, o sistema retorna para o menu inicial com uma mensagem ao topo, mostrando qual música está sendo tocada e qual o artista respónsavel. Caso todas as músicas da playlist tenham sido percorridas, o sistema imprime uma mensagem notificando o acontecimento.
<br><br>

"Sair"
<br>
É uma funcionalidade que fecha o programa e o prompt de comando. Tchau-tchau usuário, volte sempre!
<br><br>

## Limitações do Programa:
<br>
O programa não consegue restringir as entradas que recebe, assim, ele pode receber um texto no lugar de um número, ocasionando em bugs.
<br>
O programa não possui um banco de dados, assim, todos o dados modificados serão perdidos ao fim do programa.

## Dificuldades encontradas durante o desenvolvimento:
