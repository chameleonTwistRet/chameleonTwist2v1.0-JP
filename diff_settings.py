version = "jp"
basename = "chameleontwist2"

def apply(config, args):
    config['baseimg'] = f'baserom.z64'
    config['myimg'] = f'build/chameleontwist2'
    config['mapfile'] = f'build/{basename}.map'
    config['source_directories'] = ['src', 'include']
    config['objdump_flags'] = ['-M','reg-names=32']
