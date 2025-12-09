//
// pch.h
//

/**
 * \file pch.h
 * \brief Precompiled header u¿ywany przez projekt testowy.
 *
 * \details
 * Plik `pch.h` pe³ni rolê nag³ówka prekompilowanego (PCH) w projekcie testów wykorzystuj¹cym Google Test.
 * Zawiera jedynie nag³ówek Google Test, dziêki czemu kompilacja testów jest szybsza przy wielokrotnym buildzie.
 *
 * Instrukcje konfiguracji:
 * - Ten plik powinien byæ kompilowany w pliku implementacyjnym `pch.cpp` z ustawieniem
 *   __Precompiled Header__ = __Create Precompiled Header__ (dla pliku tworz¹cego PCH).
 * - Pozosta³e pliki Ÿród³owe projektu testowego powinny u¿ywaæ tego PCH (ustawienie __Precompiled Header__ = __Use Precompiled Header__).
 * - Jeœli kompilator zg³asza b³¹d „cannot open include file 'gtest/gtest.h'”, dodaj œcie¿kê do nag³ówków Google Test w:
 *   __Project Properties > C/C++ > General > Additional Include Directories__.
 *
 * \note
 * - Pozostawiono `#pragma once` zamiast tradycyjnych stra¿ników makro (#ifndef/#define/#endif).
 * - U¿ycie PCH przyspiesza kompilacjê, ale wymaga spójnej konfiguracji plików Ÿród³owych w projekcie.
 *
 * \author GitHub Copilot
 * \date grudnia 09, 2025
 */

#pragma once

#include "gtest/gtest.h"
