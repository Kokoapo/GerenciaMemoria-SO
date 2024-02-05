# GerenciaMemoria-SO
## 2° Trabalho de SO
### Objetivo: Determinar o número de falhas de páginas de diferentes algoritmos de substituição de páginas
### O trabalho deverá considerar um processador com tamanho de página de 4096 bytes, e implementar: 
1) Geração da reference string e apresentar o número de entradas da mesma, comparando o tamanho original do log com reference string gerada.  Ex: o log tem originalmente 10 acessos à memória, resultando em uma reference string com 5 entradas. Portanto a reference string em 0,5 do tamanho do log original. 
2) A partir do reference string obtido no item (1), obter o número de falhas de página considerando diferentes tamanhos de  frames livres (4, 8, 16, 32) nos algoritmos OPT e LRU. 