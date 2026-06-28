using System;

// Nombre: Juan Erminio Perez D. - Matrícula: 25-SSON-2-001
// marlen Crismel Espinal A. - Matrícula: 25-SSON-2-002

// Tarea 2
// Archivo: Tarea2_ISR.cs
// Profesor: Gamalier Reyes del Carmen
// Actividad: Flujo de Control (parte 1)
// Desarrolla un programa que lee por teclado el sueldo mensual de un empleado
// y determina cuánto debe pagar de ISR según la escala DGII 2026.
// Muestra en pantalla el sueldo y el monto a pagar de ISR.
// Si no aplica ISR, muestra: Sueldo: RD$30,000.00 ISR: N/A
// La escala anual usada es:
// - Hasta RD$416,220.00: exento
// - De RD$416,220.01 a RD$624,329.00: 15% del excedente sobre RD$416,220.01
// - De RD$624,329.01 a RD$867,123.00: RD$31,216.00 + 20% del excedente sobre RD$624,329.01
// - Sobre RD$867,123.01: RD$79,776.00 + 25% del excedente sobre RD$867,123.01
// El programa calcula ISR anual con esta escala y lo divide entre 12 para obtener el ISR mensual.

Console.WriteLine("==================================================");
Console.WriteLine("             CÁLCULO DE ISR - DGII 2026           ");
Console.WriteLine("==================================================");

decimal sueldoMensual = LeerDecimal("Ingrese el sueldo mensual del empleado (RD$): ");
decimal sueldoAnual = sueldoMensual * 12m;

decimal isrAnual = CalcularIsrAnual(sueldoAnual);

decimal isrMensual = isrAnual / 12m;

Console.WriteLine("\n==================================================");
Console.WriteLine("                 RESULTADO DEL ISR               ");
Console.WriteLine("==================================================");

if (isrAnual == 0m)
{
    Console.WriteLine($"Sueldo: RD${sueldoMensual:N2} ISR: N/A");
}
else
{
    Console.WriteLine($"Sueldo: RD${sueldoMensual:N2} ISR: RD${isrMensual:N2}");
}

Console.WriteLine("--------------------------------------------------");
Console.WriteLine($"Sueldo anual calculado: RD${sueldoAnual:N2}");
Console.WriteLine($"ISR anual calculado  : RD${isrAnual:N2}");
Console.WriteLine($"ISR mensual          : RD${isrMensual:N2}");
Console.WriteLine("==================================================");
Console.WriteLine("\nPresione cualquier tecla para salir...");
Console.ReadKey();

static decimal CalcularIsrAnual(decimal sueldoAnual)
{
    const decimal umbral1 = 416220.00m;
    const decimal umbral2 = 624329.00m;
    const decimal umbral3 = 867123.00m;

    if (sueldoAnual <= umbral1)
    {
        return 0m;
    }

    if (sueldoAnual <= umbral2)
    {
        return (sueldoAnual - umbral1) * 0.15m;
    }

    if (sueldoAnual <= umbral3)
    {
        return 31216.00m + (sueldoAnual - umbral2) * 0.20m;
    }

    return 79776.00m + (sueldoAnual - umbral3) * 0.25m;
}

static decimal LeerDecimal(string mensaje)
{
    decimal valor;
    while (true)
    {
        Console.Write(mensaje);
        string? entrada = Console.ReadLine();

        if (entrada != null && decimal.TryParse(entrada.Trim(), out valor) && valor >= 0)
        {
            return valor;
        }

        Console.WriteLine("Entrada inválida. Por favor, ingrese un número válido.");
    }
}
