set repo (git rev-parse --show-toplevel 2>/dev/null)

set -x VCPKG_ROOT $repo/vcpkg
set -x PATH $VCPKG_ROOT:$PATH

