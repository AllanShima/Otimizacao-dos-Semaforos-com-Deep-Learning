# código pra testar qual porta usb o arduino tá conectado

import serial
import serial.tools.list_ports

def test_serial_connection():
    # Lista todas as portas COM disponíveis
    ports = serial.tools.list_ports.comports()
    print("Portas COM disponíveis:")
    for port in ports:
        print(port)

    # Tente se conectar à porta COM4
    try:
        arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)
        print("Conexão estabelecida com sucesso!")
        arduino.close()
    except serial.SerialException as e:
        print(f"Erro ao tentar se conectar: {e}")

test_serial_connection()