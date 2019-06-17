ZigBee es muy similar al Bluetooth pero con algunas diferencias y ventajas para domótica:

Una red ZigBee puede constar de un máximo de 65535 nodos distribuidos en subredes de 255 nodos, frente a los ocho máximos de una subred (Piconet) Bluetooth. 
Menor consumo eléctrico que el Bluetooth. En términos exactos, ZigBee tiene un consumo de 30 mA transmitiendo y de 3 μA en reposo, frente a los 40 mA transmitiendo y 0,2 mA en reposo que tiene el Bluetooth. Este menor consumo se debe a que el sistema ZigBee se queda la mayor parte del tiempo dormido, mientras que en una comunicación Bluetooth esto no se puede dar, y siempre se está transmitiendo y/o recibiendo. 
Tiene una velocidad de hasta 250 kbit/s, mientras que en Bluetooth es de hasta 3000 kbs. 
Debido a las velocidades de cada uno, uno es más apropiado que el otro para ciertas cosas. Por ejemplo, mientras que el Bluetooth se usa para aplicaciones como los teléfonos móviles y la informática casera, la velocidad del ZigBee se hace insuficiente para estas tareas, desviándolo a usos tales como la Domótica, los productos dependientes de la batería, los sensores médicos, y en artículos de juguetería, en los cuales la transferencia de datos es menor.

En ZigBee nos encontramos con tres categorías de nodos.

El primero y más importante ya que ha de existir obligatoriamente en una red. El Coordinador ZigBee es el nodo más completo y se encarga de controlar toda la red y los caminos para su comunicación. 
Por debajo tenemos el Router ZigBee que interconecta los nodos para poder ejecutar código del usuario, es decir, ofrece un nivel de aplicación dentro de la torre de protocolos. 
Por último, el Dispositivo final ZigBee sólo recibe información y se comunica únicamente con el nodo padre. La ventaja de este dispositivo es que puede permanecer dormido y ‘despertarse’ en ciertos momentos para alargar la duración de batería.
 
Sin duda que ZigBee es una alternativa interesante para la comunicación entre distintos dispositivos que necesiten de un consumo energético reducido. Al contrario que el Bluetooth o el WiFi, ZigBee es una opción a tener en cuenta a la hora de domotizar una casa. Además, el Internet de las Cosas puede recurrir a esta tecnología en lugar de a dispositivos conectados por WiFi.
Por ejemplo, creando un nodo central con conexión a internet y con suministro energético constante se podrían verificar todos los aspectos de una vivienda. 
ZigBee permite tres topologías de red:
Topología en estrella: el coordinador se sitúa en el centro. 
Topología en árbol: el coordinador será la raíz del árbol. 
Topología de malla: al menos uno de los nodos tendrá más de dos conexiones. 

La topología más interesante es la topología de malla. Ésta permite que si, en un momento dado, un nodo del camino falla y se cae, pueda seguir la comunicación entre todos los demás nodos debido a que se rehacen todos los caminos. La gestión de los caminos es tarea del coordinador.
El paso siguiente es ver el ZigBee en funcionamiento, para esto tenemos el siguiente ejemplo que envía los datos de un contador de 0 a 9 por un enlace ZigBee.
