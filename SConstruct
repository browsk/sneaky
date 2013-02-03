#coding=utf8
 
env = Environment()
 
mcu = 'atmega328p'
 
if len(COMMAND_LINE_TARGETS):
  Target = COMMAND_LINE_TARGETS[0]
else:
  Target = ''
 
# Optimization level, can be [0, 1, 2, 3, s].
opt = "2"
 
env['CC'] = 'avr-gcc -mmcu='+mcu+' -O'+opt
env['CPPDEFINES'] = {'F_CPU' : '16000000UL'}

env.Append(CCFLAGS = "-Wall")
 
# Make elf
env.Program(Target+'.elf', [Glob('*.c')])
#env.Program(Target+'.elf', [Glob('Library/*/*.c'), 'Tests/'+Target+'.c'])
 
# Make hex
env.Command(Target+".hex", Target+".elf", 'avr-objcopy -j .text -j .data -O ihex $SOURCE $TARGET')
 
# Show memory usage
env.Command(None, Target+".hex", "avr-size $SOURCE")
 
# Program the thing
env.Command(None, Target+".hex", 'sudo avrdude -F -V -c arduino -P /dev/ttyACM0 -p m328p -b 115200 -U  flash:w:$SOURCE')
