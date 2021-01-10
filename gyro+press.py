# -*- coding: utf-8 -*-
"""
Created on Fri Jan  8 14:21:17 2021

@author: thomas
"""



import serial
from pynput.mouse import Button, Controller
mouse = Controller()

ser = serial.Serial('COM4', baudrate = 9600, timeout= 1)

numbers = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]

event_click= 0
while 1:
    arduinoData= ser.readline().decode('ascii')
    
    if (arduinoData[0:1] in numbers):     #se il primo valore è un numero, abbiamo superato la calibratura
        #---------------parte codice che analizza le coordinate del giroscopio
        primo=arduinoData.find("-")
        secondo=arduinoData.find("|")
        pprimo=primo+1
        z_coord_str=arduinoData[pprimo:secondo]    #la coordinata z risiede tra -  e |
        z_coord=int(z_coord_str)
        terzo=arduinoData.find("/")
        ssecondo=secondo+1
        x_coord_str=arduinoData[ssecondo:terzo]   #la coordinata x risiede tra | e /
        x_coord=int(x_coord_str)
        #mouse.position=x_coord, z_coord      #muove il mouse rispetto alla posizione assoluta
        #print(x_coord, z_coord)
       #---------------fine parte codice che analizza le coordinate del giroscopio 
        
        if (arduinoData[0]=="0" and event_click==0):     #stato di relax
            mouse.position=x_coord, z_coord
            print("nulla")
        
            
        elif (arduinoData[0] !="0" and event_click==0):    #stato in cui si contrae
            if arduinoData[0]=="1":
                mouse.position=x_coord, z_coord
                mouse.press(Button.left)
                print("click sinistro")
                event_click=1
            elif (arduinoData[0]=="2"):   
                mouse.position=x_coord, z_coord
                mouse.press(Button.right)
                print("tasto destro")
                #muovi mouse
                event_click=1
        if (arduinoData[0]!="0" and event_click==1):
            mouse.position=x_coord, z_coord
            
            
            print("tenendo premuto")
        if (arduinoData[0]=="0" and event_click==1):
            mouse.position=x_coord, z_coord
            mouse.release(Button.left)
            print("rilascio")
            event_click=0
            mouse.release(Button.left)
            mouse.release(Button.right)
