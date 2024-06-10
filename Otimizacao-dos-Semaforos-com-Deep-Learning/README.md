# configuração inicial
`pip install -r requirements.txt`

- Cria um mapa no SUMO netedit e salva na pasta maps

- cd na pasta maps

`python randomTrips.py -n cruzamento1.net.xml -r cruzamento1.rou.xml -e 500`

randomTrips.py = arquivo python contendo informações para manipular o sumo a partir to python
-n = network(mapa)
-r = rota (que será feito o treino)
-e = limite de tempo

essa linha vai criar um arquivo 'cruzamento1.rou.xml' por 500 epochs para o network 'cruzamento1.net.xml'

é necessário providenciar os arquivos recém criados no arquivo de configuração: 'configuration.sumocfg'

`<input>`        
  `<net-file value='maps/cruzamento1.net.xml'/>`
  `<route-files value='maps/cruzamento1.rou.xml'/>`
`</input>`

utilize o train.py para treinar o modelo para essa network

`python train.py --train -e 50 -m modelo_cruzamento1 -s 500`

esse código irá treinar o modelo por 50 epochs e criar um arquivo modelo_cruzamento1 que rodará por 500
-e = o total de epochs
-m = modelo que será salvo na pasta models
-s = pede pra simulação rodar por 500 steps
--train = pede para train.py treinar o modelo

no fim da simulação, train.py vai gerar um gráfico tempo_vs_epoch e salvar automaticamente na pasta plots com o nome do modelo.

é possível usar train.py para rodar o modelo pré treinado no SUMO GUI









 `python train.py -m modelo_cruzamento1 -s 500`