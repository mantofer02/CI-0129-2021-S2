% Estudiante: Marco Ferraro Rodriguez
% Carne: B82957

origen_animal(lomito).
origen_animal(pollo).
origen_animal(pescado).
origen_animal(leche).
origen_animal(mantequilla).
origen_animal(huevo).
origen_animal(miel).
origen_animal(queso).
origen_animal(atun).

carne(lomito).
carne(pollo).
carne(pescado).
carne(atun).

es_vegetariano(erik).
es_vegano(cesar).

es_alergico_a(graciela, cebolla).

% Plato pasta
tiene(pasta, pasta).
tiene(pasta, oregano).
tiene(pasta, tomate).
tiene(pasta, aceite).
tiene(pasta, sal).

% Plato hongos al horno
tiene(hongos_al_horno, hongos).
tiene(hongos_al_horno, queso).
tiene(hongos_al_horno, mantequilla).
tiene(hongos_al_horno, sal).

% Plato ensalada cesar
tiene(ensalada_cesar, lechuga).
tiene(ensalada_cesar, tomate).
tiene(ensalada_cesar, sal).
tiene(ensalada_Cesar, vinagre).

% Plato helados
tiene(helado, miel).
tiene(helado, leche).
tiene(helado, fresa).

% Principal de plato especial
principal(pollo).
principal(lomito).
principal(pescado).
principal(atun).
principal(hongos).

acompañamiento(papa).
acompañamiento(hongos).
acompañamiento(zucchini).
acompañamiento(arroz).

% tienen que ir en mayuscula
% Ingredientes que P no puede comer
% Este se trabajo en negacion, por las relaciones
no_puede_comer(P, I):-
    es_alergico_a(P, I);
    (es_vegano(P), origen_animal(I));
    (es_vegetariano(P), carne(I))
    .

% Comida C que P puede pedir en el restaurante
puede_pedir(P, C):-
    (tiene(C, I), \+ no_puede_comer(P, I)).

% El especial esta hecho de  X y Y.
% Se pregunta si una P puede pedir dicha combinacion
puede_pedir_especial(P, X, Y):-
	\+ no_puede_comer(P, cebolla), 
    \+ no_puede_comer(P, vinagre), 
    \+ no_puede_comer(P, sal), 
    principal(X), 
    acompañamiento(Y), 
    \+ no_puede_comer(P, X) , 
    \+ no_puede_comer(P, Y).