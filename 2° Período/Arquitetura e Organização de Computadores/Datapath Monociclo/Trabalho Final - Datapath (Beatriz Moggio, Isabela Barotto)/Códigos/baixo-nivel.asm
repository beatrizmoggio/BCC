# R = add, sub, slt (12 pontos)
# Aritmeticas com Imediato = addi (5 pontos)
# Desvios Condicionais = beq (15 pontos)
# Desvios Incondicionais = J (10 pontos)
# Operacoes de Memoria = lw, sw (30 pontos)
# TOTAL = 12 + 5 + 15 + 10 + 30 = 72 pontos


Main:
	# Inicializa as variaveis a, b, result, soma, i
	addi $s0, $0, 2			# $s0 = a = 2
	addi $s1, $0, 7			# $s1 = b = 7
	add $s2, $0, $0			# $s2 = result = 0
	add $s3, $0, $0			# $s3 = soma = 0
	addi $s4, $s0, 1		# $s4 = i = a + 1


	# Desvios Condicionais (beq) + Intrucoes R (add, sub, slt) = 15 + 4 + 4 + 4 = 27 pontos
	IF1:
		beq $s0, $s1, ELSE1	# se a == b ? ELSE1 : PROX_LINHA
		sub $s2, $s0, $s1	# result = a - b
		j IF2
	ELSE1:
		add $s2, $s0, $s1	# result = a + b
		j MEMORIA
		
	IF2:
		slt $t0, $s0, $s1     	# $t0 = (a < b) ? 1 : 0
    		beq $t0, $0, ELSE2	# se $t0 == 0 ? IF3 : PROX_LINHA
    		add $s2, $s0, $s0     	# result = a + a
    		j WHILE
    	ELSE2:
    		add $s2, $s1, $s1     	# result = b + b
    		j MEMORIA
		
		
	# Desvios Incondicionais (j) + Aritmeticas com Imediato (addi) = 10 + 5 = 15 pontos
	WHILE:
		slt $t0, $s4, $s1	# $t0 = i < b
		beq $t0, $0, FOR	# se i > b : FOR
    		add $s3, $s3, $s4	# soma = soma + i
    		addi $s4, $s4, 1	# i = i + 1
    		j WHILE 		# volta para WHILE
 
 
	FOR:
		slt $t0, $s0, $s4
		beq $t0, $0, MEMORIA
		sub $s3, $s3, $s4
		addi $s4, $s4, -1
		j FOR 
 	# Operacoes de Memoria (lw, sw) = 15 + 15 = 30 pontos
 	MEMORIA:
 		addi $s5, $0, 20	# $s5 = 0
 		sw $s0, 0($s5)		# mem[2] = a
 		lw $s1, 0($s5)		# b = mem[2]




# R = add, sub, slt (12 pontos)
# Aritméticas com Imediato = addi (5 pontos)
# Desvios Condicionais = beq (15 pontos)
# Desvios Incondicionais = J (10 pontos)
# Operações de Memória = lw, sw (30 pontos)
# TOTAL = 12 + 5 + 15 + 10 + 30 = 72 pontos

Main:
	# Inicializa as variáveis a, b, result, soma, i
	addi $s0, $0, 2			# $s0 = a = 2
	addi $s1, $0, 7			# $s1 = b = 7
	add $s2, $0, $0			# $s2 = result = 0
	add $s3, $0, $0			# $s3 = soma = 0
	addi $s4, $s0, 1		# $s4 = i = a + 1


	# Desvios Condicionais (beq) + Intruções R (add, sub, slt)	
IF1:
		beq $s0, $s1, ELSE1	# se a == b ? ELSE1 : PROX_LINHA
		sub $s2, $s0, $s1	# result = a - b
		j IF2
	ELSE1:
		add $s2, $s0, $s1	# result = a + b
		j MEMORIA
		
	IF2:
		slt $t0, $s0, $s1     	# $t0 = (a < b) ? 1 : 0
    		beq $t0, $0, ELSE2	# se $t0 == 0 ? IF3 : PROX_LINHA
    		add $s2, $s0, $s0     	# result = a + a
    		j WHILE
    	ELSE2:
    		slt $t0, $s1, $s0     	# $t0 = (b < a) ? 1 : 0
    		beq $t0, $0, WHILE	# se $t0 == 0 ? WHILE : PROX_LINHA
    		add $s2, $s1, $s1     	# result = b + b
		
		
	# Desvios Incondicionais (j) + Aritméticas com Imediato (addi)
	WHILE:
		slt $t0, $s4, $s1	# $t0 = i < b
		beq $t0, $0, MEMORIA	# se i > b : MEMORIA
    		add $s3, $s3, $s4	# soma = soma + i
    		addi $s4, $s4, 1	# i = i + 1
    		j WHILE			# volta para WHILE
 
 
 	# Operações de Memória (lw, sw)
 	MEMORIA:
 		addi $s5, $0, 20	# $s5 = -4 
 		sw $s0, 0($s5)		# mem[2] = a
 		lw $s1, 0($s5)		# b = mem[2]
