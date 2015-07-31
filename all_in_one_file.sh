#!/bin/bash

fichiers=

for nom in $*; do
    isClass=false
    fichier1="$nom".cpp
    fichier2=

    # Si c'est une classe
    if [ "${nom^}" = "$nom" ]; then
        isClass=true
        fichier2="$nom".h
    fi

    fichiers="$fichiers $fichier2 $fichier1"
done

cat $fichiers > one_file.txt