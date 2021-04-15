
#include <gtest/gtest.h>

/*
 * 1) Da spiegare che le Transazioni sono semplici impostate sugli utenti (prelievo e deposito) (Fatto)
 * 2) Aggiungere metodi: cancellazione, modifica e ricerca transazione dato una data o un altro parametro (in corso)
 * 3) Aggiungere metodo comparatore per confrontare due oggetti. (fatto, da testare)
 * 4) Usare list al posto di vector (fatto)
 * 5) Eliminare varie classi management e ridefinire i metodi di I/O sulle classi di entità (in corso)
 * 6) Inserire try catch su apertura/chiusura del file (in corso)
 * 7) Testing (in corso)
 */

int main() {
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}