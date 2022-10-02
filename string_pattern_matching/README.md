# String Pattern Matching

Este problema pode ser descrito como: a partir de um **texto** qualquer e um **padrão** de caracteres, descobrir:

- se esse padrão está contido no texto; e
- em qual posição começa.

## Abordagem Simplista

É uma abordagem de força bruta. Utilizando dois loops aninhados:

- o loop externo itera sobre o texto;
- o loop interno itera sobre o padrão buscado;
- testa todas as possibilidades, pois para cada posição do texto, verifica se há a correspondência com o padrão.

## Outras Abordagens

- Shift-Or
- Backward DAWG $^1$  Matching (BDM): Correspondência Invertida em Grafo de Palavras
- Boyer-Moore (BM)

$^1$ Deterministic Acyclic Word Graph (DAWG) -> Grafo Acíclico Determinístico de Palavras
