# progetto8
Esercitazione in C: XDR, RPC, comunicazione remota Server Client

# PDF
<a href="http://lia.disi.unibo.it/Courses/RetiT/materiale/esercitazioni/es8/svolta8.pdf">Svolto</a> <a href="http://lia.disi.unibo.it/Courses/RetiT/materiale/esercitazioni/es8/proposta8.pdf">Proposta</a>

# NOTE
I file: scan_clnt.c, scan_svc.c, scan_xdr.c, scan.h 
sono generati automaticamente attraverso il comando "rpcgen -a scan.x" e NON vanno modificati direttamente.

Il codice dei metodi è definito in scan_proc.c, mentre scan_client.c e scan_server.c implementano rispettivamente il Client e il Server (e la loro comunicazione).

Il file scan.x definisce le strutture dati e i metodi da usare in remoto e se modificato bisogna rieseguire rpcgen e cambiare l'implementazione dei metodi in scan_proc.c.
Per questo se è necessario modificare scan.x dovete prima comunicarlo al gruppo.
