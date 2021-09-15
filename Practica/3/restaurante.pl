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
es_alergico_a(graciela, leche).

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

% tienen que ir en mayuscula
puede_comer(P, I):-
	
       ( +/ es_alergico_a(P, I);
       (es_vegano(P), origen_animal(I));
       (es_vegetariano(P), origen_animal(I))
       ).
	
