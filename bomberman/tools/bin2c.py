#!/usr/bin/env python
import sys
import os
from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument('-I', '--include', dest = 'includes', action = 'append', default = [])
parser.add_argument('infile')
parser.add_argument('outdir')

def chunks(l, n):
    """ Yield successive n-sized chunks from l.
    """
    for i in range(0, len(l), n):
        yield l[i:i+n]

def replace_ext(filename, ext):
    (root, old_ext) = os.path.splitext(filename)
    return root + ext

def gen_c(f, data, varname):
    size = len(data)
    f.write('char {}[{}] = {{\n'.format(varname, size))

    for chunk in chunks(data, 16):
        f.write('   ')
        for c in chunk:
            f.write(' 0x{:02x},'.format(ord(c)))
        f.write('\n')

    f.write('};\n')

def gen_h(f, data, varname, includes = []):
    size = len(data)

    f.write('#ifdef __cplusplus\n')
    f.write('extern "C" {\n')
    f.write('#endif\n\n')

    f.write('#include <nds.h>\n')
    for include in includes:
        f.write('#include "{include}"\n'.format(include = include))
    f.write('\n')

    f.write('extern const u8 {varname}[{size}];\n'.format(varname = varname, size = size))
    f.write('\n')
    f.write('#define {varname}_end ({varname} + {size})\n'.format(varname = varname, size = size))
    f.write('#define {varname}_size ({size})\n'.format(varname = varname, size = size))

    f.write('\n')
    f.write('#ifdef __cplusplus\n')
    f.write('}\n')
    f.write('#endif\n')

def main(args):
    in_filename = args.infile
    out_dir = args.outdir

    (root, ext) = os.path.splitext(in_filename)
    varname = os.path.basename(in_filename).replace('.', '_')

    c_filename = in_filename + '.c'
    c_filename = os.path.join(out_dir, os.path.basename(c_filename))
    h_filename = replace_ext(in_filename, '.h')
    h_filename = os.path.join(out_dir, os.path.basename(h_filename))

    with open(in_filename, 'rb') as f:
        data = f.read()

    with open(c_filename, 'w+') as f:
        gen_c(f, data, varname)

    with open(h_filename, 'w+') as f:
        gen_h(f, data, varname, includes = args.includes)

if __name__ == '__main__':
    main(parser.parse_args())
