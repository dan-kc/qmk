{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs =
    { self, nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
# qmk flash -c -kb bastardkb/charybdis/3x5/v2/splinky_3 -km via
        buildInputs = [
          pkgs.qmk
          pkgs.dfu-util
          pkgs.udev
          pkgs.python313Packages.appdirs
        ];
      };
    };
}
