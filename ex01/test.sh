#!/bin/bash

# Script de test pour le programme RPN
# Utilisation : ./test_rpn.sh

# Fonction pour lancer le test
run_test() {
    local expr="$1"
    local expected="$2"

    echo "Test: $expr"
    result=$(./RPN "$expr")
    echo "Résultat obtenu : $result"
    echo "Résultat attendu: $expected"

    if [ "$result" = "$expected" ]; then
        echo "✅ OK"
    else
        echo "❌ ERREUR"
    fi
    echo "------------------------"
}

echo "=== TESTS RPN ==="

# Cas simples
run_test "2 3 +" "5"
run_test "5 2 -" "3"
run_test "4 2 /" "2"
run_test "6 3 *" "18"

# Cas blocs imbriqués
run_test "1 2 + 3 4 + *" "21"        # (1+2)*(3+4) = 3*7 = 21
run_test "5 1 2 + 4 * + 3 -" "14"    # 5 + (1+2)*4 - 3 = 5+12-3 = 14
run_test "3 4 2 * 1 5 - / +" "1"     # 3 + (4*2)/(1-5) = 3 + 8/(-4) = 3-2=1

# Cas plus compliqués
run_test "1 2 3 + + 4 +" "10"        # 1+(2+3)+4=10
run_test "2 3 * 4 5 * +" "26"        # 2*3 + 4*5 = 6+20=26
run_test "1 2 / 3 4 + *" "0"       # (1/2)*(3+4)=0*7=0
run_test "5 1 2 + 3 * 4 - +" "10"    # 5 + (1+2)*3 -4 = 5+9-4=10

# Cas erreurs
run_test "1 +" "Error : You got it all messed up here buddy"           # opérateur sans deux nombres
run_test "2 0 /" "Error : Division by 0"          # division par zéro
run_test "+ 1 2" "Error : You got it all messed up here buddy"       # opérateur au début
run_test "3 4 5 +" "Error : You got it all messed up here buddy"       # trop d’opérandes restantes

# Cas plus extrêmes
run_test "1 2 + 3 4 + * 5 -" "16"   # ((1+2)*(3+4)) -5 = 21-5=16
run_test "1 2 3 4 5 + + + +" "15"   # 1+(2+(3+(4+5)))=15

echo "=== FIN DES TESTS ==="
