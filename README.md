# README #

This is an editor for transfer functions in the Voreen XML format.
The code was successfully compiled with Visual Studio 2015 and Qt 5.5.

![editor.png](https://bitbucket.org/repo/kGLpoM/images/185556157-editor.png)


```
#!xml

<?xml version="1.0" ?>
<VoreenData version="1">
    <TransFuncIntensity type="TransFuncIntensity">
        <alphaMode value="1" />
        <gammaValue value="1" />
        <domain x="0" y="1" />
        <threshold x="0" y="1" />
        <Keys>
            <key type="TransFuncMappingKey">
                <intensity value="0.14115535" />
                <split value="false" />
                <colorL r="153" g="0" b="255" a="0" />
            </key>
            <key type="TransFuncMappingKey">
                <intensity value="0.15267822" />
                <split value="false" />
                <colorL r="129" g="90" b="255" a="11" />
            </key>
...
        </Keys>
    </TransFuncIntensity>
</VoreenData>

```