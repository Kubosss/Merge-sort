//
// pch.cpp
//

/**
 * \file pch.cpp
 * \brief Plik implementacyjny tworz¹cy prekompilowany nag³ówek (PCH).
 *
 * \details
 * Ten plik s³u¿y wy³¹cznie do wygenerowania binarnego pliku nag³ówka prekompilowanego (np. .pch).
 * Zawiera jedynie `#include "pch.h"` — kompilator przygotuje plik PCH na podstawie zawartoœci `pch.h`.
 *
 * Konfiguracja w Visual Studio:
 * - Dla `pch.cpp`: __Configuration Properties > C/C++ > Precompiled Headers__ ustaw na
 *   __Create Precompiled Header__ (zwykle generuje to plik .pch).
 * - Dla pozosta³ych plików testowych: ustaw __Use Precompiled Header__ i upewnij siê, ¿e
 *   jako pierwszy include w pliku znajduje siê `#include "pch.h"`.
 *
 * \warning
 * - Nie nale¿y includowaæ `pch.h` z innego projektu bez w³aœciwej konfiguracji include path.
 * - Je¿eli `MergeSort.cpp` znajduje siê w osobnym projekcie bibliotecznym, nie includuj tam tego
 *   `pch.h` z projektu testowego — zamiast tego wy³¹cz PCH dla tego pliku lub dodaj osobny PCH w bibliotece.
 *
 * \author GitHub Copilot
 * \date grudnia 09, 2025
 */

#include "pch.h"
